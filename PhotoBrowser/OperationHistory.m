// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by .

#import "OperationHistory.h"
#import "ImageOperation.h"

NS_ASSUME_NONNULL_BEGIN

@interface OperationHistory()

@property (readonly, nonatomic) NSArray<id<ImageOperation>> *operations;

@property (readonly, nonatomic) NSArray<NSArray<UIImage *> *> *cachedImages;

@property (readonly, nonatomic) NSArray<UIImage *> *originalInput;

@property (readonly, nonatomic) NSUInteger costFromLastCache;

@end

@implementation OperationHistory

@end

NS_ASSUME_NONNULL_END
