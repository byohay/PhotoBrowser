// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import "VersionMetadata.h"
#import "PhotoMetadata.h"
#import "UserMetadata.h"
#import "OperationHistory.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^PushCompletionBlock) (NSError * _Nullable error);
typedef void (^PhotoCompletionBlock) (NSArray<PhotoMetadata *> *photosMetadata, NSError * _Nullable error);
typedef void (^VersionCompletionBlock) (NSArray<VersionMetadata *> *operationMetadata, NSError * _Nullable error);
typedef void (^OperationHistorycompletionBlock) (OperationHistory *operationHistory, NSError * _Nullable error);

@interface PhotosFetcher : NSObject

- (instancetype)initWithCachedImagesInterval:(NSUInteger)cachedImagesInterval;

- (void)localPhotos:(NSRange)photosRange
    uponCompletion:(PhotoCompletionBlock)completion;

- (void)fetchPhotos:(NSRange)photosRange
          forUser:(UserMetadata *)userMetadata
      uponCompletion:(PhotoCompletionBlock)completion;

// Feches history metadata
- (void)photoVersions:(NSRange)versionsRange
              ofPhoto:(PhotoMetadata *)photoMetadata
       uponCompletion:(VersionCompletionBlock)completion;

// gets updates of manager (avoids fetching a heavy history)
- (void)fetchPhotoHistory:(PhotoMetadata *)photoMetadata
        currentOperations:(OperationHistory *)operationsHistory
           uponCompletion:(OperationHistorycompletionBlock)completionBlock;


/// Should be able to distinguish between the case where the operationsManager completely
/// overrides the previous history and the case where the \c operationsManager only adds to the
/// previous history.
- (void)pushToServer:(OperationHistory *)operationHistory
        userMetadata:(UserMetadata *)userMetadata
       photoMetadata:(PhotoMetadata *)photoMetadata
      uponCompletion:(PushCompletionBlock)pushCompletionBlock;

- (void)saveLocally:(OperationHistory *)operationHistory
      photoMetadata:(PhotoMetadata *)photoMetadata
     uponCompletion:(PushCompletionBlock)pushCompletionBlock;

@property (readonly, nonatomic) NSString *myUsername;

@end

NS_ASSUME_NONNULL_END
