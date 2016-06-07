// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ImageOperation <NSObject>

- (NSArray<UIImage *> *)perform:(NSArray<UIImage *> *)inputImages;

- (BOOL)canOverrideOperation:(id<ImageOperation>)operation;

@property (readonly, nonatomic) CGFloat cost;

@property (readonly, nonatomic) NSUUID *operationUUID;

@end

NS_ASSUME_NONNULL_END
