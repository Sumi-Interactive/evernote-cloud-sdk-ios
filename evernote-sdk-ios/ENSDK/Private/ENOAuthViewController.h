/*
 * Copyright (c) 2012-2014 by Evernote Corporation, All rights reserved.
 *
 * Use of the source code and binary libraries included in this package
 * is permitted under the following terms:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@class ENOAuthViewController;

@protocol ENOAuthViewControllerDelegate <NSObject>
- (void)oauthViewControllerDidCancel:(ENOAuthViewController *)sender;
- (void)oauthViewControllerDidSwitchProfile:(ENOAuthViewController *)sender;
- (void)oauthViewController:(ENOAuthViewController *)sender didFailWithError:(NSError *)error;
- (void)oauthViewController:(ENOAuthViewController *)sender receivedOAuthCallbackURL:(NSURL *)url;
@end

@interface ENOAuthViewController : UIViewController

@property (nonatomic, weak) id<ENOAuthViewControllerDelegate> delegate;

- (id)initWithAuthorizationURL:(NSURL *)authorizationURL
           oauthCallbackPrefix:(NSString *)oauthCallbackPrefix
                   profileName:(NSString *)currentProfileName
                allowSwitching:(BOOL)isSwitchingAllowed
                      delegate:(id<ENOAuthViewControllerDelegate>)delegate;

- (void)updateUIForNewProfile:(NSString*)newProfile
         withAuthorizationURL:(NSURL*)authURL
          oauthCallbackPrefix:(NSString *)oauthCallbackPrefix;

@end
