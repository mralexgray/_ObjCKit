


@interface NSDictionary(F)
- _Void_ each:(ObjObjBlk) block;
- (NSDictionary *) map:(Obj_ObjObjBlk) block;
- reduce:(ReduceDictBlock) block withInitialMemo:(id) memo;
- (NSDictionary*) filter:(Bool_ObjObjBlk) block;
- (NSDictionary*) reject:(Bool_ObjObjBlk) block;
- (BOOL) isValidForAll:(Bool_ObjObjBlk) block;
- (BOOL) isValidForAny:(Bool_ObjObjBlk) block;
- (NSNumber *) countValidEntries:(Bool_ObjObjBlk) block;
- max:(CompareDictBlock) block;
- min:(CompareDictBlock) block;
@end


@interface NSArray(F)

- _Void_ each:(ObjBlk) block;
- _Void_ eachWithIndex:(ObjIntBlk) block;
- (NSA*) map:(Obj_ObjBlk) block;
-   (id) reduce:(ReduceArrayBlock) block withInitialMemo:(id) memo;
- (NSA*) filter:(Bool_ObjBlk) block;
- (NSA*) reject:(Bool_ObjBlk) block;
- (BOOL) isValidForAll:(Bool_ObjBlk) block;
- (BOOL) isValidForAny:(Bool_ObjBlk) block;
- (NSN*) countValidEntries:(Bool_ObjBlk) block;

-   (id) max:(CompareArrayBlock) block;
-   (id) min:(CompareArrayBlock) block;
- (NSA*) sort:(NSComparator) block;
- (NSD*) group:(Obj_ObjBlk) block;
- (NSA*) dropWhile:(Bool_ObjBlk) block;

@property (readonly) id first;
@property (readonly) NSA* reverse;

- (NSA*) arrayUntilIndex:(NSI)idx;
- (NSA*) arrayFromIndexOn:(NSI)idx;

//  + (NSA*) arrayFrom:(NSI)from to:(NSI) to;
@end

typedef void (^VoidNumberIterator)(NSNumber*num);
typedef   id (^MapNumberBlock)    (NSNumber*num);

@interface NSNumber(F)

- (NSA*) mapTimes:(MapNumberBlock) block;
- _Void_ times:(NumBlk) block;
@end
