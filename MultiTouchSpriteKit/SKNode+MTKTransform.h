//
//  SKNode+MTKTransform.h
//  MultiTouchKitDemo
//
//  Created by Simon Voelker on 04.02.14.
//  Copyright (c) 2014 i10. All rights reserved.
//

#import <SpriteKit/SpriteKit.h>
#import "MTKUtil.h"
#import "NSValue+CGElements.h"


/**
 *  These constraints can be used to define which properties of the node are modified by the transformation.
 */
typedef NS_OPTIONS(NSInteger, MTKNodeTransformationConstraints)
{
    /**
     *  The transformation moves the node.
     */
    MTKNoteMoveable = 1 << 0,
    /**
     *  The transformation scales the node..
     */
    MTKNoteScalabe  = 1 << 1,
    /**
     *  The transformation rotates the node.
     */
    MTKNoteRotatable  = 1 << 2,
    /**
     *  The transformation moves, scales, and rotates the node.
     */
    MTKNoteTransformable  = 1 << 3,
    /**
     *  The transformation does not do anything to the node.
     */
    MTKNoteFixed = 1 << 5
};

/**
 *  This SKNode category allows to transform the node accordantly to a set of CGPoints.
 */
@interface SKNode (MTKTransform)

@property(getter=isTouchable) BOOL touchable;

@property(nonatomic)MTKNodeTransformationConstraints transformationConstraints;

#pragma mark -
#pragma mark Transformations

/** @name Core methods */
/**
  This method transform the node accordinaly to the points in startPoints and EndPoints.
 
   @param startPoints An NSArray containing CGPoints as NSValues.
   @param startNode   The coordinatesytem of the startPoints.
  @param endPoints   An NSArray containing CGPoints as NSValues.
   @param endNode     The coordinatesytem of the startPoints.
 
 
   @return The dictionary contains the absoulte transformation values for:
    * For the key "position" the position of the node as CGPoint stored in a NSValue.
 * For the key "scale" the scale of the node as CGSize stored in a NSValue.
 * For the key "angle" the rotationAngle of the node as float stored in a NSNumber.
 
  @discussion This method currently only takes the first two points of the array to calculated the transformation.
 */

-(NSDictionary*)transformFromPoints:(NSArray*)startPoints inCoordinatesOfNode:(SKNode*)startNode toPoints:(NSArray*)endPoints inCoordinatesOfNode:(SKNode*)endNode;

-(NSDictionary*)transformFromScenePoints:(NSArray*)startPoints toScenePoints:(NSArray*)endPoints;

#if TARGET_OS_IPHONE
/**
 *  Takes the first two touches and transforms the node accordingly. The node will be transformed with respect to the transformationConstraints.
 *
 * @discussion Method only accessible on iOS 
 *  @param touches A set of UITouches.
 */

-(void)transformWithUITouches:(NSSet *)touches;
#endif


#pragma mark -
#pragma mark Utilities
/** @name Utilities */
/**
 *  This method recursively searches for the top most Node which is the SKScene.
 *  @discussion This function is need since most touches are in the coordinates of the SKScene
 *
 *  @return the root element as SKNode
 */
-(SKNode*)rootScene;

/**
 *  This method check if the userData property of the SKNode is initialized. If not it will create the NSMutableDictionary
 */
-(void)checkUserData;


@end