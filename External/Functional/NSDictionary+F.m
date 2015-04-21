//
//  NSDictionary+F.m
//  Functional
//
//  Created by Hannes Walz on 07.04.12.
//  Copyright 2012 leuchtetgruen. All rights reserved.
//
#import "F+Private.h"

@implementation NSDictionary(F)

- _Void_ each:(ObjObjBlk) block {
    [F eachInDict:self withBlock:block];
}

- (NSDictionary *) map:(Obj_ObjObjBlk) block {
    return [F mapDict:self withBlock:block];
}

- reduce:(ReduceDictBlock) block withInitialMemo:(id) memo {
    return [F reduceDictionary:self withBlock:block andInitialMemo:memo];
}

- filter:(Bool_ObjObjBlk) block {
    return [F filterDictionary:self withBlock:block];
}

- (NSDictionary*) reject:(Bool_ObjObjBlk) block {
    return [F rejectDictionary:self withBlock:block];
}

- (BOOL) isValidForAll:(Bool_ObjObjBlk) block {
    return [F allInDictionary:self withBlock:block];
}

- (BOOL) isValidForAny:(Bool_ObjObjBlk) block {
    return [F anyInDictionary:self withBlock:block];
}

- (NSNumber *) countValidEntries:(Bool_ObjObjBlk) block {
    return [F countInDictionary:self withBlock:block];
}

- max:(CompareDictBlock) block {
    return [F maxDict:self withBlock:block];
}

- min:(CompareDictBlock) block {
    return [F minDict:self withBlock:block];
}
@end
