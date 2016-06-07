// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import "ToneMappingOperation.h"

NS_ASSUME_NONNULL_BEGIN

@interface ToneMappingOperation ()

@property (readonly, nonatomic) CGFloat brightness;

@property (readonly, nonatomic) ImageProcessor *processor;

@end

@implementation ToneMappingOperation

- (instancetype)initWithBrightness:(CGFloat)brightness
{
  if (self = [super init]) {
    _isUndoAvailable = YES;
    _cost = 0.1;
    _brightness = brightness;
  }
  return self;
}

- (UIImage *)perform:(UIImage *)inputImage {
  [self.processor brightness:self.brightness forImage:inputImage];
}

@end

NS_ASSUME_NONNULL_END
