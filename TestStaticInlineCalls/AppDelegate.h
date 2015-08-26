//
//  AppDelegate.h
//  TestStaticInlineCalls
//
//  Created by Brian Michel on 8/26/15.
//  Copyright (c) 2015 Tumblr. All rights reserved.
//

#import <UIKit/UIKit.h>

static inline BOOL static_inline_function(BOOL trueish) {
    NSString *warningSuppressor = @"i'm here to suppress a warning!";
    NSString *string = [[NSString alloc] initWithString:warningSuppressor];
    NSLog(@"Here's a string: %@", string);
    return trueish;
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;


@end

