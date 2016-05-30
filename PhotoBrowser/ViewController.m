//
//  ViewController.m
//  PhotoBrowser
//
//  Created by Ben Yohay on 24/05/2016.
//  Copyright © 2016 Lightricks. All rights reserved.
//

#import "ViewController.h"

#import "OperationsManager.h"
#import "PhotosFetcher.h"

NS_ASSUME_NONNULL_BEGIN

@interface ViewController ()

@property (readonly, nonatomic) PhotosFetcher *fetcher;

@property (nonatomic) NSArray<PhotoMetadata *> *photosMetadata;

@property (nonatomic) NSArray<VersionMetadata *> *versionsMetadata;

@property (readonly, nonatomic) OperationsManager *operationsManager;

@property (nonatomic) OperationHistory *operationHistory;

@property (nonatomic) OperationPosition *firstOperation;

@property (nonatomic) OperationPosition *secondOperation;

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
}

- (void)test {
  [self fetchPhotos];
  [self fetchVersions];
  [self fetchPhotoWithVersion];
  [self doRedo];
  [self doUndo];
  
  [self push];
}
- (void)fetchPhotos {
  [self.fetcher localPhotos:NSMakeRange(0, 5)
             uponCompletion:^(NSArray<PhotoMetadata *> * _Nonnull metadata, NSError * _Nullable error) {
               self.photosMetadata = metadata;
             }];
}

- (void)fetchVersions {
  [self.fetcher photoVersions:NSMakeRange(0, 3)
                      ofPhoto:self.photosMetadata[0]
               uponCompletion:^(NSArray<VersionMetadata *> * versionsMetadata, NSError * _Nullable error) {
                 self.versionsMetadata = versionsMetadata;
               }];
  }

- (void)fetchPhotoWithVersion {
  [self.fetcher fetchPhotoHistory:self.photosMetadata[0]
        currentOperations:self.operationHistory
        uponCompletion:^(OperationHistory *operationHistory, NSError * _Nullable error) {
          self.operationHistory = operationHistory;
        }];
}

- (void)doRedo {
  [self.operationsManager positionInVersion:1 operationsHistory:self.operationHistory
                             uponCompletion:^(OperationPosition * _Nonnull operationPosition, NSError * _Nullable error) {
                               self.firstOperation = operationPosition;
                             }];
  
  
  if ([self.operationsManager isRedoAvailable:self.operationHistory
                            operationPosition:self.firstOperation]) {
    
    [self.operationsManager redo:self.operationHistory
               operationPosition:self.firstOperation
                  uponCompletion:^(OperationPosition * _Nonnull operationPosition, NSError * _Nullable error) {
                    self.firstOperation = operationPosition;
                  }];
  }
}

- (void)doUndo {
  [self.operationsManager positionInVersion:5 operationsHistory:self.operationHistory
                             uponCompletion:^(OperationPosition * _Nonnull operationPosition, NSError * _Nullable error) {
                               self.secondOperation = operationPosition;
                             }];

  if ([self.operationsManager isUndoAvailable:self.operationHistory
                            operationPosition:self.secondOperation]) {
    
    [self.operationsManager undo:self.operationHistory
               operationPosition:self.secondOperation
                  uponCompletion:^(OperationPosition * _Nonnull operationPosition, NSError * _Nullable error) {
                    self.secondOperation = operationPosition;
                  }];
  }
}

- (void)push {
  [self.fetcher saveLocally:self.operationHistory
              photoMetadata:self.photosMetadata[2]
             uponCompletion:^(NSError * _Nullable error) {
              }];
}

@end

NS_ASSUME_NONNULL_END
