// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import <Foundation/Foundation.h>

#import "ImageOperation.h"
#import "PhotoMetadata.h"
#import "VersionMetadata.h"
#import "OperationHistory.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^FetchOperationsCompletionBlock) (NSArray<id<ImageOperation>> *operations, NSError * _Nullable error);

typedef void (^PushOperationsCompletionBlock) (NSError * _Nullable error);

@interface PhotoServer : NSObject

- (void)versionStartingFrom:(NSUInteger)version
               completionBlock:(FetchOperationsCompletionBlock)completionBlock
                     fromPhoto:(PhotoMetadata *)photoMetadata;

- (void)pushVersionStartingFrom:(NSUInteger)version
                      toHistory:(OperationHistory *)history
                      fromPhoto:(PhotoMetadata *)photoMetadata
                completionBlock:(PushOperationsCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
