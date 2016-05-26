// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import <UIKit/UIKit.h>

#import "ImageOperation.h"

NS_ASSUME_NONNULL_BEGIN

@interface OperationsManager : NSObject

- (instancetype)initWithImage:(UIImage *)originalImage
         cachedImagesInterval:(NSUInteger)cachedImagesInterval;

- (void)performOperationsOnImage:(NSArray<id<ImageOperation>> *)operations;

- (void)goToVersion:(NSUInteger)version;

- (void)undo;
- (void)redo;

- (BOOL)isUndoAvailable;
- (BOOL)isRedoAvailable;

@property (readonly, nonatomic) UIImage *currentImage;

@property (nonatomic) NSUInteger capacity;

- (NSUInteger)numberOfCommonOperationsFromStart:(NSArray<id<ImageOperation>> *)otherOperations;

@end

NS_ASSUME_NONNULL_END
