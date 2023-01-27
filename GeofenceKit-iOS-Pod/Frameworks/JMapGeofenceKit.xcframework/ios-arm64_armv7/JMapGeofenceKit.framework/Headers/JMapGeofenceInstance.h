//
//  JMapGeofenceInstance.h
//  JMapGeofenceKit
//
//  Created by Louie Yuen on 2018-02-27.
//  Copyright © 2018 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMapGeofenceObject.h"

@class JMapGeofenceObject;
@class Polygon;

/**
 *  The JMapGeofenceInstance model
 */
@interface JMapGeofenceInstance : NSObject

/**
 * GeofenceInstance's parent geofence object
 */
@property (nonatomic, strong, readonly, nullable) JMapGeofenceObject *parent;

/**
 * GeofenceInstance's name
 */
@property (nonatomic, strong, readonly, nullable) NSString *instanceName;

/**
 * GeofenceInstance's Id
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *instanceId;

/**
 * GeofenceInstance's feature type
 */
@property (nonatomic, strong, readonly, nullable) NSString *featureType;

/**
 * GeofenceInstance's floor association
 */
@property (nonatomic, strong, readonly, nullable) JMapFloor *floor;

/**
 * GeofenceInstance's floor sequence
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *floorSequence;

/**
 * GeofenceInstance's coordinates in lat/long
 */
@property (nonatomic, strong, readonly, nullable) NSArray *coordinates;

/**
 * GeofenceInstance's associated map Id
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *mapId;

/**
 * GeofenceInstance's elevation
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *elevation;

/**
 * GeofenceInstance's associated building Id
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *buildingId;

/**
 * GeofenceInstance's associated floor Id
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *floorId;

/**
 * GeofenceInstance's associated venue Id
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *venueId;

/**
 * JMapGeofenceInstance init method
 *
 *  @param dict NSDictionary properties of the geofence instance
 *  @return A JMapGeofenceInstance object
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

/**
 * Getter for the geofence instance's centroid
 *
 *  @return The geofence instance centroid CGPoint
 */
- (CGPoint)getCentroid;

/**
 * Getter for the geofence instance's bounds
 *
 *  @return The geofence instance bounds CGRect
 */
- (CGRect)getBounds;

/**
 * Getter for the geofence instance's polygon
 *
 *  @return The geofence instance polygon Polygon class
 */
- (nullable Polygon *)getPolygon;

/**
 * Getter for the geofence instance's coordinates
 *
 *  @return The geofence instance coordinates in lat/long NSArray of NSValues
 */
- (nonnull NSArray <NSValue *>*)getCoordinates;

/**
 * Getter for the geofence instance's local coordinates
 *
 *  @return The geofence instance coordinates in x,y NSArray of NSValues
 */
- (nonnull NSArray <NSValue *>*)getLocalCoordinates;

@end
