// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by.

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface OperationPosition : NSObject

- (instancetype)initWithIndex:(NSUInteger)position images:(NSArray<UIImage *> *)imagesAfterOperation;

@property (readonly, nonatomic) NSUInteger operationIndex;

@property (readonly, nonatomic) NSArray<UIImage *> *imagesAfterOperation;

@end

NS_ASSUME_NONNULL_END
