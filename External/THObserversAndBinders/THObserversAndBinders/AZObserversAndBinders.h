
//  THObserver.h - THObserversAndBinders
//  Created by James Montgomerie on 29/11/2012. Copyright (c) 2012 James Montgomerie.

@interface THObserver : NSObject

#pragma mark - Block-based observers.


+ observerForObject:x
            keyPath:(NSString*)kP
              block:(VBlk)b ___

+ observerForObject:x
            keyPath:(NSString*)kP
     oldAndNewBlock:(ObjObjBlk)b ___

+ observerForObject:object
            keyPath:(NSString*)kP
            options:(NSKeyValueObservingOptions)opts
        changeBlock:(DBlk)b ___

#pragma mark - Target-action based observers.

/*! Target-action based observers take a selector with a signature with 0-4
 arguments, and call it like this:

 0 arguments: [target action];

 1 argument:  [target actionForObject:object];

 2 arguments: [target actionForObject:object keyPath:keyPath];

 3 arguments: [target actionForObject:object keyPath:keyPath change:changeDictionary];
     Don't expect anything in the change dictionary unless you supply some
     NSKeyValueObservingOptions.

 4 arguments: [target actionForObject:object keyPath:keyPath oldValue:oldValue newValue:newValue];
     NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew will be
     automatically added to your options if they're not already there and you
     supply a 4-argument callback.

 The action should not return any value (i.e. should be declared to return
 void).

 Both the observer and the target are weakly referenced internally.
*/

+ observerForObject:x
            keyPath:(NSString*)kP
             target:t
             action:(SEL)a;

+ observerForObject:x
            keyPath:(NSString*)kP
            options:(NSKeyValueObservingOptions)opts
             target:t
             action:(SEL)a;


/*! A second kind of target-action based observer; takes a selector with a
 signature with 1-2 arguments, and call it like this:

 1 argument:  [target actionWithNewValue:newValue];

 2 arguments: [target actionWithOldValue:oldValue newValue:newValue];

 3 arguments: [target actionForObject:object oldValue:oldValue newValue:newValue];

 The action should not return any value (i.e. should be declared to return
 void).

 Both the observer and the target are weakly referenced internally.
*/
+ observerForObject:x
            keyPath:(NSString*)kP
             target:t
        valueAction:(SEL)vAction;

+ observerForObject:object
            keyPath:(NSString*)kP
            options:(NSKeyValueObservingOptions)opts
             target:t
        valueAction:(SEL)vAction;


#pragma mark - Lifetime management

//  This is a one-way street. Call it to stop the observer functioning. \
    The THObserver will do this cleanly when it deallocs, \
    but calling it manually can be useful in ensuring an orderly teardown.

- _Void_ stopObserving;

@end

@interface THBinder : NSObject

typedef id(^THBinderTransformationBlock)(id value);

+   binderFromObject:from keyPath:(NSString*)fromKp
            toObject:to   keyPath:(NSString*)toKp;

+   binderFromObject:from keyPath:(NSString*)fromKp
            toObject:to   keyPath:(NSString*)toKp
    valueTransformer:(NSValueTransformer*)vT;

+   binderFromObject:from keyPath:(NSString*)fromKp
            toObject:to   keyPath:(NSString*)toKp
 transformationBlock:(THBinderTransformationBlock)tBlock;

//  This is a one-way street. Call it to stop the observer functioning. \
    The THBinder will do this cleanly when it deallocs, \
    but calling it manually can be useful in ensuring an orderly teardown.

- _Void_ stopBinding;

@end
