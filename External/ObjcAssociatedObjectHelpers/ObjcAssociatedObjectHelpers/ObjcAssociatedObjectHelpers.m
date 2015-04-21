
/*  NSObject+AssociatedDictionary.m -  ObjcAssociatedObjectHelpers

	Created by Jon Crooke on 01/10/2012. - Copyright (c) 2012 Jonathan Crooke. All rights reserved.

	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#import "ObjcAssociatedObjectHelpers.h"

// was NSObject+AssociatedDictionary.m


void useMyHelperPlease(){
    NSLog(@"do nothing, just for make mylib linked");
}


@implementation NSObject (AssociatedDictionary)

//SYNTHESIZE_ASC_OBJ_LAZY(
- (NSMutableDictionary*) associatedDictionary {

    id x = objc_getAssociatedObject(self, _cmd);
    if (!x) objc_setAssociatedObject(self, _cmd, x = NSMutableDictionary.new, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    return x;
}

@end