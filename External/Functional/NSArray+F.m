//
//  NSArray+F.m
//  Functional
//
//  Created by Hannes Walz on 07.04.12.
//  Copyright 2012 leuchtetgruen. All rights reserved.
//

#import "F+Private.h"

@implementation NSArray(F)

- _Void_ each:(ObjBlk)b                     { [F eachInArray:self withBlock:b]; }
- _Void_ eachWithIndex:(ObjIntBlk)b   { [F eachInArrayWithIndex:self withBlock:b]; }

-   (id)            reduce:(ReduceArrayBlock)b  
           withInitialMemo: memo               { return [F reduceArray:self withBlock:b andInitialMemo:memo]; }

- (NSA*)               map:(Obj_ObjBlk)b       { return [F mapArray:self withBlock:b];        }
- (NSA*)            filter:(Bool_ObjBlk)b      { return [F filterArray:self withBlock:b];      }
- (NSA*)            reject:(Bool_ObjBlk)b      { return [F rejectArray:self withBlock:b];      }
- (BOOL)     isValidForAll:(Bool_ObjBlk)b      { return [F allInArray:self withBlock:b];       }
- (BOOL)     isValidForAny:(Bool_ObjBlk)b      { return [F anyInArray:self withBlock:b];       }
- (NSN*) countValidEntries:(Bool_ObjBlk)b      { return [F countInArray:self withBlock:b];     }
-   (id)               max:(CompareArrayBlock)b   { return [F maxArray:self withBlock:b];         }
-   (id)               min:(CompareArrayBlock)b   { return [F minArray:self withBlock:b];         }
- (NSA*)         dropWhile:(Bool_ObjBlk)b      { return [F dropFromArray:self whileBlock:b];   }

// This is really just an alias
- (NSA*)  sort:(NSComparator)b   { return [self sortedArrayUsingComparator:b];     }
- (NSD*) group:(Obj_ObjBlk)b   { return [F groupArray:self withBlock:b];  }

-   (id) first    { return self[0]; } // Just a helper method
- (NSA*) reverse  { return self.reverseObjectEnumerator.allObjects; } // Just a helper method

//+ (NSA*)        arrayFrom:(NSI)from to:(NSI)to { return [@(from) to:@(to)]; }
// Just a helper method
- (NSA*)  arrayUntilIndex:(NSI)idx  { return [self subarrayWithRange:NSMakeRange(0,               idx)];  }
// Just a helper method
- (NSA*) arrayFromIndexOn:(NSI)idx { return [self subarrayWithRange:NSMakeRange(idx,self.count - idx)];  }

@end
