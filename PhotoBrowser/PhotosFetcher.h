// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import "OperationMetadata.h"
#import "OperationsManager.h"
#import "PhotoMetadata.h"
#import "UserMetadata.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^FetchCompletionBlock) (OperationsManager *, NSError * _Nullable error);
typedef void (^PushCompletionBlock) (NSError * _Nullable error);

@interface PhotosFetcher : NSObject

- (NSArray<PhotoMetadata *> *)photoForUser:(UserMetadata *)userMetadata;
- (NSArray<PhotoMetadata *> *)getLocalPhotos;

- (NSArray<OperationMetadata *> *)getPhotoRevisions:(PhotoMetadata *)photoMetadata;

// gets updates of manager (avoids fetching a heavy history)
- (void)getOperationsManager:(FetchCompletionBlock)completionBlock
                   fromPhoto:(PhotoMetadata *)photoMetadata
             localOperations:(OperationsManager *)operationsManager
               withOperation:(OperationMetadata *)operationMetadata;

/// Should be able to distinguish between the case where the operationsManager completely
/// overrides the previous history and the case where the \c operationsManager only adds to the
/// previous history.
- (void)pushToServer:(PushCompletionBlock)pushCompletionBlock
          operations:(OperationsManager *)operationsManager
        userMetadata:(UserMetadata *)userMetadata
       photoMetadata:(PhotoMetadata *)photoMetadata;

@end

NS_ASSUME_NONNULL_END
