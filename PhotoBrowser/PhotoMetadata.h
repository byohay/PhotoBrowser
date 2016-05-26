// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PhotoMetadata : NSObject

@property (readonly, nonatomic) NSURL *path;
@property (readonly, nonatomic) NSString *title;
@property (readonly, nonatomic) UIImage *thumbnail;

@end

NS_ASSUME_NONNULL_END
