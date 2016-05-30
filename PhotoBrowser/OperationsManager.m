// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import "OperationsManager.h"

#import <Foundation/Foundation.h>

#import "ImageOperation.h"

NS_ASSUME_NONNULL_BEGIN

@interface OperationsManager()

@end

@implementation OperationsManager

- (void)undo:(OperationHistory *)operationsHistory
operationPosition:(OperationPosition *)currentPosition
uponCompletion:(OperationPositionCompletionBlock)completionBlock {
  id<ImageOperation> operation = [operationsHistory at:currentPosition.operationIndex];
  __block id<OperationInput> input;
  
  if(operation.isUndoAvailable) {
      [operation performUndo:currentPosition.inputAfterOperation
                      uponCompletion:^(id<OperationInput> inputAfterOperation, NSError * _Nullable error) {
                        input = inputAfterOperation;
      }];
  } else {
    NSUInteger cachedInputIndex = (currentPosition.operationIndex / self.cachedImagesInterval);
    input = [operationsHistory cachedInputAt:cachedInputIndex];
    
    for (;cachedInputIndex < currentPosition.operationIndex - 1; ++cachedInputIndex) {
      operation = [operationsHistory at:cachedInputIndex];
      
      [operation perform:input
          uponCompletion:^(id<OperationInput> inputAfterOperation, NSError * _Nullable error) {
            input = inputAfterOperation;
          }];
    }
  }
  
  OperationPosition *position = [[OperationPosition alloc]
                                 initWithIndex:currentPosition.operationIndex - 1
                                 input:input];
  
  NSError *error;
  
  completionBlock(position, error);
}

@end

NS_ASSUME_NONNULL_END
