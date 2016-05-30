// Copyright (c) 2016 Lightricks. All rights reserved.
// Created by .

#import "ImageOperation.h"
#import "OperationInput.h"

NS_ASSUME_NONNULL_BEGIN

@interface OperationHistoryCreator : NSObject

- (void)createHistoryOperation:(NSArray<id<ImageOperation>> *)operations
                      original:(id<OperationInput>)input
           cachedImageInterval:(NSUInteger)interval;
@end

NS_ASSUME_NONNULL_END
