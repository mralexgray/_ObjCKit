
/*! Useful protocol for any object that implements both setter and getters for both FRAME and BOUNDS.
    and that can be genuinely represented in those terms.
 */

@Vows RectLike
@Reqd _RO _Rect frame ___  // MUST be implemented (in a category is OK)
@Optn

//- _Void_ setFrame:_Rect_ r; ///     -frame  & -setFrame:

_AT _Rect bounds ___            /// AND -bounds & -setBounds:   AND shoould accurately reflect those values.

- _Void_ setFrame:_Rect_ r ___

_AT _Cord   anchorPoint,    /// If unimplemented
               position ___
_AT _Rect    superframe ___     /// WILL store these, for you, if unimplemented.. and make anchorPoint & position calculations meaningful.

@concrete

_RO  AZA   insideEdge;                     // !!!
_RO _Text insideEdgeHex;
_NA _UInt   arMASK;
_NA _Rect   r;                        // alias [frame]
_NA _Size   size;

_NA _Flot w,        h,              // alias [size/width]
          x,        y,              // position
          width,    height,         // bounds
          midX,     maxX,
          midY,     maxY,
          posX,     posY,
          anchX,    anchY;
_NA _Cord minXmaxY, midXmaxY, maxXmaxY,
          minXmidY, midXmidY, maxXmidY,
          minXminY, midXminY, maxXminY,
          centerPt,
          bOrigin,
          origin,
          apex ___

_RO _Flot perimeter, area;              // 2 * (width + height)

- _IsIt_      isLargerThan __Ｐ(RectLike) r ___
- _IsIt_     isSmallerThan __Ｐ(RectLike) r ___
- _IsIt_         isRectLke __Ｐ(RectLike) r ___
- _IsIt_  isLargerThanRect __Rect_ r ___
- _IsIt_ isSmallerThanRect __Rect_ r ___
- _IsIt_        isSameRect __Rect_ r ___

/*! Protocol factory methods for all conformant classes! */

/*! CAL *l = [CAL x:23 y:33 w:100 h:9]; -> l: CALayer #-1 of -1!  AZNotFound f:{{23 x 33},{100 x 9 }} b:{{ 0 x  0},{100 x 9 }} */
+ _Kind_ x:_Flot_ x
         y:_Flot_ y
         w:_Flot_ w
         h:_Flot_ h ___

// 0 - 4 * NSNumber.. dims + optional NSValue rect for superframe.
+ _Kind_ rectLike __Numb_ d1, ... NS_REQUIRES_NIL_TERMINATION ___
+ _Kind_ withRect __Rect_ r ___                     /*! NSV *r = [NSV withRect:AZRectBy(100,200)];  */


- _Void_ iterate:(CordBlk)b;
￭

//  _CP  SizeChange onChangeDimensions;
//- _Void_ setOnChangeDimensions:(_Void(^)(_Size oldSz,_Size newSz))c;
//- _Void_ iterateWithIndex:(RowColBlkIdx)b;

//@prop_ NSAlignmentOptions   alignment;

DECLARECONFORMANCE( View,    RectLike )
DECLARECONFORMANCE( CAL,     RectLike )

#if MAC_ONLY
DECLARECONFORMANCE( NSW,     RectLike )
DECLARECONFORMANCE( NSScreen,RectLike )
DECLARECONFORMANCE( NSIMG,   RectLike )
#endif

@interface AZRect : NSO <RectLike>

- (INST) shiftedX:(CGF)x y:(CGF)y w:(CGF)w h:(CGF)h;

@end

#define AZR             AZRect

#define $AZR(_r_)       [AZR withRect:_r_]
#define AZRBy(_x_,_y_)  $AZR(AZRectBy(_x_,_y_))
#define AZRDim(_d_)     $AZR(AZRectFromDim(_d_))
#define AZRUNDERMENU     AZR.screenFrameUnderMenu

// {  CGF width, height;	}
//_RONSR r;
#ifdef UNIMPLENETED 
+ _Kind_ screnFrameUnderMenu;
_RO CGF 	area;
- (BOOL)     contains:(id)obj;
//- (BOOL)    contaiNSP:(NSP)p;
- (BOOL) containsRect:(NSR)r;
#endif
