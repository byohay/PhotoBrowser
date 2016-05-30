// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by.

#import <UIKit/UIKit.h>
#import "OperationInput.h"

NS_ASSUME_NONNULL_BEGIN

@interface OperationPosition : NSObject

- (instancetype)initWithIndex:(NSUInteger)position input:(id<OperationInput>)input;

@property (readonly, nonatomic) NSUInteger operationIndex;

@property (readonly, nonatomic) id<OperationInput> inputAfterOperation;

@end

NS_ASSUME_NONNULL_END
