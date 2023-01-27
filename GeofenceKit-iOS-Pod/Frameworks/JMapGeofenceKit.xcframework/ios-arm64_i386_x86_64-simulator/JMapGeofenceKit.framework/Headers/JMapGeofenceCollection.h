//
//  JMapGeofenceCollection.h
//  JMapGeofenceKit
//
//  Created by Louie Yuen on 2018-02-27.
//  Copyright © 2018 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapGeofenceKit/JMapGeofenceObject.h>
#import <UIKit/UIKit.h>

/**
 *  The JMapGeofenceCollection model
 */
@interface JMapGeofenceCollection : JMapBaseCollection

/**
 * Get all object in collection
 *
 * @return an array of JMapGeofence
 */
- (nonnull NSArray <JMapGeofenceObject *>*)getAll;

/**
 * Get By External ID
 * @param externalId ID to search for
 *
 * @return An array of JMapGeofence associase to the external ID
 */
- (nonnull NSArray <JMapGeofenceObject *>*)getByExternalId:(nonnull NSString *)externalId;

/**
 * Get JMapGeofence by ID in collection
 * @param id ID to search for
 *
 * @return JMapGeofence associated to ID or a nil if JMapBaseModel does not exists
 */
- (nullable JMapGeofenceObject *)getById:(NSInteger)id;

/**
 * Get JMapGeofence by name in collection
 * @param name String to search for in geofence collections
 *
 * @return Array of JMapGeofence associated to name provided
 */
- (nonnull NSArray<JMapGeofenceObject *>*)getByName:(nonnull NSString *)name;

/**
 * Get JMapGeofence by map in collection
 * @param map JMapMap to search for in geofence collections
 *
 * @return Array of JMapGeofence associated to map object provided
 */
- (nonnull NSArray<JMapGeofenceObject *>*)getByMap:(nonnull JMapMap *)map;

@end
