// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import <UIKit/UIKit.h>

#import "ImageOperation.h"
#import "OperationHistory.h"
#import "OperationPosition.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^OperationPositionCompletionBlock) (OperationPosition *operationPosition, NSError * _Nullable error);

typedef void (^OperationHistoryCompletionBlock) (OperationHistory *history,
                                                 OperationPosition *operationPosition, NSError * _Nullable error);

@interface OperationsManager : NSObject

- (void)positionInVersion:(NSUInteger)version
  operationsHistory:(OperationHistory *)operationsHistory
     uponCompletion:(OperationPositionCompletionBlock)completionBlock;

- (void)undo:(OperationHistory *)operationsHistory
operationPosition:(OperationPosition *)currentPosition
    uponCompletion:(OperationPositionCompletionBlock)completionBlock;

- (void)redo:(OperationHistory *)operationsHistory
operationPosition:(OperationPosition *)currentPosition
uponCompletion:(OperationPositionCompletionBlock)completionBlock;

- (BOOL)isUndoAvailable:(OperationHistory *)operationsHistory
      operationPosition:(OperationPosition *)position;

- (BOOL)isRedoAvailable:(OperationHistory *)operationsHistory
      operationPosition:(OperationPosition *)position;

/// Create a new OperationHistory with a new (possibly expanded) cache.
// overites from position onwards
- (void)addOperations:(NSArray<id<ImageOperation>> *)operations
            toHistory:(OperationHistory *)operationHistory
           atPosition:(OperationPosition *)position
       uponCompletion:(OperationHistoryCompletionBlock)completionBlock;

@property (nonatomic) NSUInteger capacity;

@property (nonatomic) NSUInteger cachedImagesInterval;

@end

NS_ASSUME_NONNULL_END
