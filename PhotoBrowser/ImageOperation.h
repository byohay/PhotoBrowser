// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by Ben Yohay.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OperationParametersProvider.h"
#import "OperationInput.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ImagesCompletionBlock) (id<OperationInput>, NSError * _Nullable error);

@protocol ImageOperation <NSObject>

- (void)perform:(id<OperationInput>)input
 uponCompletion:(ImagesCompletionBlock)completionBlock;

- (void)performUndo:(id<OperationInput>)input
     uponCompletion:(ImagesCompletionBlock)completionBlock;

@property (readonly, nonatomic) NSUUID *operationUUID;

@property (readonly, nonatomic) id<OperationParametersProvider> parametersProvider;

@property (readonly, nonatomic) BOOL isUndoAvailable;

@end

NS_ASSUME_NONNULL_END
