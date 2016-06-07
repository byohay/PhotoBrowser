// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import "OperationsManager.h"

#import <Foundation/Foundation.h>

#import "ImageOperation.h"

NS_ASSUME_NONNULL_BEGIN

@interface OperationsManager()

@property (readonly, nonatomic) NSUInteger cachedImagesInterval;

@end

@implementation OperationsManager

- (void)undo:(OperationHistory *)operationsHistory
operationPosition:(OperationPosition *)currentPosition
uponCompletion:(OperationPositionCompletionBlock)completionBlock {
  id<ImageOperation> operation = [operationsHistory at:currentPosition.operationIndex];
  __block NSArray<UIImage *> *input;
  id<ImageOperation> previousOperation = [operationsHistory at:currentPosition.operationIndex - 1];
  NSArray<UIImage *> *imagesAfterUndo;

  if([previousOperation canOverrideOperation:operation]) {
    imagesAfterUndo = [previousOperation perform:currentPosition.imagesAfterOperation];
  } else {
    NSArray<UIImage *> *cache = [operationsHistory cachedImagesClosestTo:currentPosition.operationIndex];
    for (;cachedInputIndex < currentPosition.operationIndex - 1; ++cachedInputIndex) {
      operation = [operationsHistory at:cachedInputIndex];
      
      [operation perform:cache
          uponCompletion:^(NSArray<UIImage *> *imagesAfterOperation, NSError * _Nullable error) {
            cache = inputAfterOperation;
          }];
    }
  }
  
  OperationPosition *position = [[OperationPosition alloc]
                                 initWithIndex:currentPosition.operationIndex - 1
                                 images:imagesAfterUndo];
  
  NSError *error;
  
  completionBlock(position, error);
}

@end

NS_ASSUME_NONNULL_END
