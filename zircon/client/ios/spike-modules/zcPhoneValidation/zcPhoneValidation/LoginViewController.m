//
//  LoginViewController.m
//  zcPhoneValidation
//
//  Created by Virendra Shakya on 12/10/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//
#import <AccountKit/AKFAccountKit.h>
#import <AccountKit/AKFPhoneNumber.h>
#import "LoginViewController.h"

@interface LoginViewController () <AKFViewControllerDelegate>
@property (nonatomic, weak) id<AKFViewControllerDelegate> delegate;
@end

@implementation LoginViewController {
  BOOL enableSendToFacebook;
  BOOL enableGetACall;
  AKFAccountKit * _accountKit;
}

- (void)logout {
  [_accountKit logOut];
}

- (void)viewDidLoad {
    [super viewDidLoad];
  
  self.view.backgroundColor = [UIColor redColor];
  _accountKit = [[AKFAccountKit alloc]
                 initWithResponseType:AKFResponseTypeAccessToken];
  
  
  [self loginWithPhone:nil];
}

- (void)viewWillAppear:(BOOL)animated
{
  [super viewWillAppear:animated];
  
  if ([_accountKit currentAccessToken]) {
      // if the user is already logged in, go to the main screen
    [self proceedToMainScreen];
  } else {
      // Show the login screen
    [self showLoginControls];
  }
}

- (void)proceedToMainScreen {
  NSLog(@"proceedToMainScreen");
}
- (void)showLoginControls {
  NSLog(@"showLoginControls");
}

- (void)loginWithPhone:(id)sender
{
  //NSString *preFillPhoneNumber = nil;
  NSString *inputState = [[NSUUID UUID] UUIDString];
  
  AKFPhoneNumber *preFillPhoneNumber = [[AKFPhoneNumber alloc] initWithCountryCode:@"+1" phoneNumber:@"4158061197"];
  UIViewController<AKFViewController> *viewController =
  [_accountKit viewControllerForPhoneLoginWithPhoneNumber:preFillPhoneNumber
                                                    state:inputState];
  [self _prepareLoginViewController:viewController]; // see above
  [self presentViewController:viewController animated:YES completion:NULL];
}

- (void)_prepareLoginViewController:(UIViewController<AKFViewController> *)loginViewController
{
  loginViewController.delegate = self;
    // Optionally, you may set up backup verification methods.
  enableSendToFacebook = YES;
  enableGetACall = YES;
}


#pragma mark -- AKFViewControllerDelegate
/**
 Called when the login completes with an authorization code response type.
 
 - Parameter viewController: the AKFViewController that was used
 - Parameter code: the authorization code that can be exchanged for an access token with the app secret
 - Parameter state: the state param value that was passed in at the beginning of the flow
 */
- (void)viewController:(UIViewController<AKFViewController> *)viewController didCompleteLoginWithAuthorizationCode:(NSString *)code state:(NSString *)state {
  NSLog(@"didCompleteLoginWithAuthorizationCode");
}

/**
 Called when the login completes with an access token response type.
 
 - Parameter viewController: the AKFViewController that was used
 - Parameter accessToken: the access token for the logged in account
 - Parameter state: the state param value that was passed in at the beginning of the flow
 */
- (void)viewController:(UIViewController<AKFViewController> *)viewController didCompleteLoginWithAccessToken:(id<AKFAccessToken>)accessToken state:(NSString *)state {
  NSLog(@"didCompleteLoginWithAccessToken");
  if (accessToken == nil) {
    return;
  }
  [_accountKit requestAccount:^(id<AKFAccount> account, NSError *error) {
      // account ID
    NSString *fbAccountID = account.accountID;
    NSString *fbAccountEmailAddress = @"<empty>";
    NSString *fbAccountPhoneNumber =  @"<empty>";
    
    if ([account.emailAddress length] > 0) {
      fbAccountEmailAddress = account.emailAddress;
    }
    else if ([account phoneNumber] != nil) {
      fbAccountPhoneNumber = [[account phoneNumber] stringRepresentation];
    }
    NSLog(@"========== FB ACCOUNT - start ================");
    NSLog(@"fbAccountID: %@", fbAccountID);
    NSLog(@"fbAccountEmailAddress: %@", fbAccountEmailAddress);
    NSLog(@"fbAccountPhoneNumber: %@", fbAccountPhoneNumber);
    NSLog(@"========== FB ACCOUNT -end ================");
  }];
  

}

/**
 Called when the login failes with an error
 
 - Parameter viewController: the AKFViewController that was used
 - Parameter error: the error that occurred
 */
- (void)viewController:(UIViewController<AKFViewController> *)viewController didFailWithError:(NSError *)error {
  NSLog(@"didFailWithError");
}

/**
 Called when the login flow is cancelled through the UI.
 
 - Parameter viewController: the AKFViewController that was used
 */
- (void)viewControllerDidCancel:(UIViewController<AKFViewController> *)viewController {
  NSLog(@"viewControllerDidCancel");
}




@end
