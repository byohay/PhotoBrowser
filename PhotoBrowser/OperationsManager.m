// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import "OperationsManager.h"

#import <Foundation/Foundation.h>

#import "ImageOperation.h"

NS_ASSUME_NONNULL_BEGIN

@interface OperationsManager()

@property (readonly, nonatomic) NSArray<id<ImageOperation>> *operations;
@property (readonly, nonatomic) NSArray<UIImage *> *cachedImages;

@property (nonatomic) NSUInteger currentOperationIndex;

@property (nonatomic) UIImage *currentImage;
@property (readonly, nonatomic) UIImage *originalImage;

@property (readonly, nonatomic) NSUInteger cachedImagesInterval;

@end

@implementation OperationsManager

@end

NS_ASSUME_NONNULL_END
