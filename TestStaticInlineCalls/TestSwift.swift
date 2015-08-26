//
//  TestSwift.swift
//  TestStaticInlineCalls
//
//  Created by Brian Michel on 8/26/15.
//  Copyright (c) 2015 Tumblr. All rights reserved.
//

import Foundation

class TestSwift: NSObject {
    func doSomething() -> String {
        let bound = static_inline_function(true)
        return bound ? "TRUE" : "FALSE"
    }
}