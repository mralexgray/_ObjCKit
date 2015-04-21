//
//  NSNumber+F.m
//  Functional
//
//  Created by Hannes Walz on 12.04.12.
//  Copyright (c) 2012 leuchtetgruen. All rights reserved.
//


#import "F+Private.h"


@implementation NSNumber(F)

- (NSArray*) mapTimes:(MapNumberBlock)blk {

  NSMutableArray *map = @[].mutableCopy;
  for (int i = 0; i < self.intValue; i++) {

    id x = nil; if ((x = blk(@(i)))) [map addObject:x];
  }

  return [map copy];
}


- _Void_ times:(NumBlk) block {
    [F times:self RunBlock:block];
}
@end
