// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import <Foundation/Foundation.h>

#import "ImageOperation.h"
#import "PhotoMetadata.h"
#import "OperationMetadata.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^FetchOperationsCompletionBlock) (NSArray<id<ImageOperation>> *operations, NSError * _Nullable error);

@interface PhotoServer : NSObject

- (void)getVersionStartingFrom:(NSUInteger)version
               completionBlock:(FetchOperationsCompletionBlock)completionBlock
                     fromPhoto:(PhotoMetadata *)photoMetadata;

@end

NS_ASSUME_NONNULL_END
