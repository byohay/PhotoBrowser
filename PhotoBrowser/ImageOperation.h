// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ImageOperation <NSObject>

- (UIImage *)perform:(UIImage *)image;

/// Returns nil when no undo is available.
- (UIImage *)performUndo:(UIImage *)image;

@property (readonly, nonatomic) NSString *operationUUID;

@end

NS_ASSUME_NONNULL_END
