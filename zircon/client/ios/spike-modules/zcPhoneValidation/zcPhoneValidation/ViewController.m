//
//  ViewController.m
//  zcPhoneValidation
//
//  Created by Virendra Shakya on 12/10/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//
#import <AccountKit/AKFAccountKit.h>
#import "ViewController.h"

@interface ViewController ()<AKFViewControllerDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  
}

- (void)_prepareLoginViewController:(UIViewController<AKFViewController> *)loginViewController
{
  loginViewController.delegate = self;
    // Optionally, you may set up backup verification methods.
//  self.enableSendToFacebook = YES;
//  self.enableGetACall = YES;
}


@end
