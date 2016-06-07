// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by.

#import <UIKit/UIKit.h>
#import "ImageOperation.h"

NS_ASSUME_NONNULL_BEGIN

@interface OperationHistory : NSObject

- (instancetype)initWithOriginalImages:(NSArray<UIImage *> *)originalImages;

- (NSArray<UIImage *> *)versionAt:(NSUInteger)index;

- (id<ImageOperation>)operationAt:(NSUInteger)operationIndex;

/// May create cache.
- (void)addOperation:(id<ImageOperation>)operation;

- (NSUInteger)differenceWith:(OperationHistory *)history;

- (BOOL)isUndoAvailable:(OperationHistory *)operationsHistory
             atPosition:(NSUInteger)position;

- (BOOL)isRedoAvailable:(OperationHistory *)operationsHistory
             atPosition:(NSUInteger)position;

@property (readonly, nonatomic) NSUInteger maximumCost;

@end

NS_ASSUME_NONNULL_END
