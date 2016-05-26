// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface OperationMetadata : NSObject

@property (readonly, nonatomic) NSUInteger *operationNumber;
@property (readonly, nonatomic) NSString *operationName;
@property (readonly, nonatomic) UIImage *imageAfterOperationThumbnail;

@end

NS_ASSUME_NONNULL_END
