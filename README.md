# SwiftTestStaticInlineCalls

This will compile fine, and then crash like this...

```
2015-08-26 10:42:35.655 TestStaticInlineCalls[48048:8726011] *** NSForwarding: warning: selector (0x1042d9c9c) for message 'alloc' does not match selector known to Objective C runtime (0x1047ca19f)-- abort
2015-08-26 10:42:35.656 TestStaticInlineCalls[48048:8726011] +[NSString alloc]: unrecognized selector sent to class 0x10465f8e0
2015-08-26 10:42:35.658 TestStaticInlineCalls[48048:8726011] *** Terminating app due to uncaught exception 'NSInvalidArgumentException', reason: '+[NSString alloc]: unrecognized selector sent to class 0x10465f8e0'
*** First throw call stack:
(
	0   CoreFoundation                      0x0000000104b20c65 __exceptionPreprocess + 165
	1   libobjc.A.dylib                     0x00000001047afbb7 objc_exception_throw + 45
	2   CoreFoundation                      0x0000000104b27fad +[NSObject(NSObject) doesNotRecognizeSelector:] + 205
	3   CoreFoundation                      0x0000000104a7e13c ___forwarding___ + 988
	4   CoreFoundation                      0x0000000104a7dcd8 _CF_forwarding_prep_0 + 120
	5   TestStaticInlineCalls               0x00000001042d9514 _TToFC21TestStaticInlineCalls9TestSwift11doSomethingfS0_FT_SS + 52
	6   TestStaticInlineCalls               0x00000001042d9336 -[AppDelegate application:didFinishLaunchingWithOptions:] + 60
	7   UIKit                               0x0000000104f15748 -[UIApplication _handleDelegateCallbacksWithOptions:isSuspended:restoreState:] + 240
	8   UIKit                               0x0000000104f16357 -[UIApplication _callInitializationDelegatesForMainScene:transitionContext:] + 2540
	9   UIKit                               0x0000000104f1919e -[UIApplication _runWithMainScene:transitionContext:completion:] + 1349
	10  UIKit                               0x0000000104f18095 -[UIApplication workspaceDidEndTransaction:] + 179
	11  FrontBoardServices                  0x0000000107ba05e5 __31-[FBSSerialQueue performAsync:]_block_invoke_2 + 21
	12  CoreFoundation                      0x0000000104a5441c __CFRUNLOOP_IS_CALLING_OUT_TO_A_BLOCK__ + 12
	13  CoreFoundation                      0x0000000104a4a165 __CFRunLoopDoBlocks + 341
	14  CoreFoundation                      0x0000000104a49947 __CFRunLoopRun + 887
	15  CoreFoundation                      0x0000000104a49366 CFRunLoopRunSpecific + 470
	16  UIKit                               0x0000000104f17b02 -[UIApplication _run] + 413
	17  UIKit                               0x0000000104f1a8c0 UIApplicationMain + 1282
	18  TestStaticInlineCalls               0x00000001042d9430 main + 80
	19  libdyld.dylib                       0x000000010752b145 start + 1
)
libc++abi.dylib: terminating with uncaught exception of type NSException
```

Converting the `static_inline_function()` defintion to just be `BOOL static_inline_function(BOOL trueish);` and having it's implementation written in the `AppDelegate.m` resolves this problem.

I guess I'm just wondering how/why this compiles, then spectacularly blows up.
