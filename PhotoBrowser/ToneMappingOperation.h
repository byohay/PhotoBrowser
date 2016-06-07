// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import "ImageOperation.h"

NS_ASSUME_NONNULL_BEGIN

@interface ToneMappingOperation : NSObject<ImageOperation>

- (UIImage *)perform:(UIImage *)inputImage;

@property (readonly, nonatomic) BOOL isUndoAvailable;

@property (readonly, nonatomic) CGFloat cost;

@end

NS_ASSUME_NONNULL_END
