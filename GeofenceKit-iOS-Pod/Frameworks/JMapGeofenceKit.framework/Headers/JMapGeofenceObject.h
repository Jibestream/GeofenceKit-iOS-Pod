//
//  JMapGeofenceObject.h
//  JMapGeofenceKit
//
//  Created by Louie Yuen on 2018-02-27.
//  Copyright © 2018 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>
#import "JMapGeofenceInstance.h"

@class JMapGeofenceInstance;

/**
 *  The JMapGeofenceObject model
 */
@interface JMapGeofenceObject : JMapBaseModel

/**
 * Geofence Name
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;

/**
 * Color of the geofence
 */
@property (nonatomic, strong, readonly, nullable) UIColor *color;

/**
 * Instances of the geofence
 */
@property (nonatomic, strong, readonly, nullable) NSMutableArray <JMapGeofenceInstance*>* geofenceInstances;

/**
 * JMapGeofenceObject init method
 *
 *  @param dict NSDictionary properties of the geofence object
 *  @return A JMapGeofenceObject instance
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
