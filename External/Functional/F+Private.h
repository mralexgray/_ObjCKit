

#import "F.h"

@interface F : NSObject

+ (void) useConcurrency;
+ (void) dontUseConcurrency;
+ (void) useQueue:(dispatch_queue_t)q;

+ (void) concurrently _ (Blk)c ___
+ (void) concurrently _ (Blk)block withQueue:(dispatch_queue_t)q;

+ (void) eachInArray:(NSArray*)arr withBlock:(ObjBlk)b ___
+ (void) eachInArrayWithIndex:(NSArray*)arr withBlock:(ObjIntBlk)b ___
+ (void) eachInDict:(NSDictionary*)dict withBlock:(ObjObjBlk)b ___

+ (NSArray*) mapArray:(NSArray*)arr withBlock:(Obj_ObjBlk)block;
+ (NSDictionary*)mapDict:(NSDictionary*)dict withBlock:(Obj_ObjObjBlk)b ___

+ (NSObject*)reduceArray:(NSArray*)arr withBlock:(ReduceArrayBlock) block andInitialMemo:(id) memo;
+ (NSObject*)reduceDictionary:(NSDictionary*)dict withBlock:(ReduceDictBlock) block andInitialMemo:memo; 

+ (NSArray*)filterArray:(NSArray*)arr withBlock:(Bool_ObjBlk)b ___
+ (NSDictionary*)filterDictionary:(NSDictionary*)dict withBlock:(Bool_ObjObjBlk)b ___

+ (NSArray*)rejectArray:(NSArray*)arr withBlock:(Bool_ObjBlk)b ___
+ (NSDictionary*)rejectDictionary:(NSDictionary*)dict withBlock:(Bool_ObjObjBlk)b ___

+ (BOOL) allInArray:(NSArray*)arr withBlock:(Bool_ObjBlk)b ___
+ (BOOL) allInDictionary:(NSDictionary*)dict withBlock:(Bool_ObjObjBlk)b ___

+ (BOOL) anyInArray:(NSArray*)arr withBlock:(Bool_ObjBlk)b ___
+ (BOOL) anyInDictionary:(NSDictionary*)dict withBlock:(Bool_ObjObjBlk)b ___

+ (NSNumber*)countInArray:(NSArray*)arr withBlock:(Bool_ObjBlk)b ___
+ (NSNumber*)countInDictionary:(NSDictionary*)dict withBlock:(Bool_ObjObjBlk)b ___

+ (NSObject*)maxArray:(NSArray*)arr withBlock:(CompareArrayBlock)b ___
+ (NSObject*)maxDict:(NSDictionary*)dict withBlock:(CompareDictBlock)b ___
+ (NSObject*)minArray:(NSArray*)arr withBlock:(CompareArrayBlock)b ___
+ (NSObject*)minDict:(NSDictionary*)dict withBlock:(CompareDictBlock)b ___

+ (NSDictionary*)groupArray:(NSArray*)arr withBlock:(Obj_ObjBlk)b ___
//    + (NSDictionary*)groupDictionary:(NSDictionary*)dict withBlock:(Obj_ObjObjBlk)b ___

+ (NSArray*)dropFromArray:(NSArray*)arr whileBlock:(Bool_ObjBlk)b ___

+ (void) times:(NSNumber*)nr RunBlock:(NumBlk)b ___

+ (void) asynchronously:(Blk)b ___
+ (void) onUIThread:(Blk)b ___
+ (NSArray*)mapRangeFrom:(NSInteger) from To:(NSInteger) to withBlock:(Obj_IntBlk)b ___
@end
