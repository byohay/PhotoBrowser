// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by.

#import "ImageOperation.h"

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface OperationHistory : NSObject

- (instancetype)initWithOperations:(NSArray<id<ImageOperation>> *)operations
                      cashedImages:(NSArray<id<OperationInput>> *)images
                     originalImage:(id<OperationInput>)originalIinput;

- (id<ImageOperation>)at:(NSUInteger)operationIndex;

- (id<OperationInput>)cachedInputAt:(NSUInteger)cachedInputIndex;

- (NSUInteger)differenceWith:(OperationHistory *)history;

@end

NS_ASSUME_NONNULL_END
