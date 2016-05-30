// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by .

#import "OperationHistory.h"

NS_ASSUME_NONNULL_BEGIN

@interface OperationHistory()

@property (readonly, nonatomic) NSArray<id<ImageOperation>> *operations;

@property (readonly, nonatomic) NSArray<id<OperationInput>> *cachedInputs;

@property (readonly, nonatomic) id<OperationInput> originalInput;

@end

@implementation OperationHistory

@end

NS_ASSUME_NONNULL_END
