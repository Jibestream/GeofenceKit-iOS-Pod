//
//  JMapGeofence.h
//  JMapGeofenceKit
//
//  Created by Louie Yuen on 2018-02-27.
//  Copyright © 2018 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapGeofenceKit/JMapGeofenceInstance.h>
#import <JMapGeofenceKit/JMapGeofenceCollection.h>
#import <JMapControllerKit/JMapControllerKit.h>
#import <JMapGeofenceKit/JMapGeofenceObject.h>

/**
 *  The JMapGeofenceDelegate model.
 */
@protocol JMapGeofenceDelegate <NSObject>

@optional
/**
 *  Delegate method for geofences entered by moving object
 *
 *  @param movingObject referenced moving object
 *  @param geofences geofences entered by moving object
 */
- (void)geofencesEnteredByMovingObject:(nullable JMapMovingObject*)movingObject geofences:(nonnull NSArray <JMapGeofenceInstance *>*)geofences;

/**
 *  Delegate method for geofences exited by moving object
 *
 *  @param movingObject referenced moving object
 *  @param geofences geofences exited by moving object
 */
- (void)geofencesExitedByMovingObject:(nullable JMapMovingObject*)movingObject geofences:(nonnull NSArray <JMapGeofenceInstance *>*)geofences;

@end

/**
 *  The JMapGeofence model
 */
@interface JMapGeofence : NSObject

#pragma mark Geofence Initialization

/**
 * Collection of all geofences
 */
@property (nonatomic, strong, readonly, nullable) JMapGeofenceCollection *geofences;

/**
 * The JMapGeofenceDelegate property
 */
@property (nonatomic, weak, nullable) id<JMapGeofenceDelegate> delegate;

/**
 * The JMapGeofence's controller reference
 */
@property (nonatomic, strong, readonly, nonnull) JMapController *controller;

/**
 *  Init With Controller : Contructor to create a JMapGeofence with controller
 *
 *  @param core JMapJCore being used in implementation
 *  @param controller JMapController being used in implementation
 *
 *  @return newly created JMapGeofence object
 */
- (nonnull instancetype)initWithCore:(nonnull JMapJCore *)core andController:(nonnull JMapController *)controller;

/**
 *  Get geofences
 *
 *  @param completionHandler returns error if error has occured with network request
 */
- (void)getGeofences:(void(^)(JMapError* _Nullable error))completionHandler;

#pragma mark Get With Geofence Methods

/**
 *  Get Bounds Of Geofence
 *
 *  @param geofence JMapGeofenceObject to retrieve the bound
 *  @param map JMapMap object to retrieve the bound
 *  @return rect bound of the Geofence
 */
- (CGRect)getBoundsOfGeofence:(nonnull JMapGeofenceObject *)geofence onMap:(nullable JMapMap *)map;

#pragma mark Geofence Drawing

/**
 *  Get Polygon Of Geofence
 *
 *  @param geofence JMapGeofenceObject to get polygon from
 *  @param map JMapMap object to get the polygon, if nil then grab all Polygon instances across all maps
 *  @return An array of polygon objects of the Geofence instances
 */
- (nonnull NSArray <Polygon *>*)getPolygonsOfGeofence:(nonnull JMapGeofenceObject *)geofence onMap:(nullable JMapMap *)map;

/**
 *  Draw Polygon(s) Of Geofence
 *
 *  @param geofence JMapGeofenceObject to draw
 *  @param map JMapMap object to draw the polygon, if nil then draws all Polygon instances across all maps
 *  @param style Optional JMapStyle object to set the styling of the Geofence on the map, default will use defined color on CMS, if none is found, sets fill to black
 */
- (void)drawPolygonsOfGeofence:(nonnull JMapGeofenceObject *)geofence onMap:(nullable JMapMap *)map withStyle:(nullable JMapStyle *)style;

/**
 *  Remove Polygon(s) Of Geofence
 *
 *  @param geofence JMapGeofenceObject to remove from the map
 *  @param map JMapMap object to draw the polygon, if nil then removes all Polygon instances across all maps
 */
- (void)removePolygonsOfGeofence:(nonnull JMapGeofenceObject *)geofence onMap:(nullable JMapMap *)map;

/**
 *  Draw Polygon Of GeofenceInstance
 *
 *  @param instance JMapGeofenceInstance to draw
 *  @param style Optional JMapStyle object to set the styling of the Geofence on the map, default will use defined color on CMS, if none is found, sets fill to black
 */
- (void)drawPolygonOfGeofenceInstance:(nonnull JMapGeofenceInstance *)instance withStyle:(nullable JMapStyle *)style;

/**
 *  Remove Polygon Of GeofenceInstance
 *
 *  @param instance JMapGeofenceInstance to remove from the map
 */
- (void)removePolygonOfGeofenceInstance:(nonnull JMapGeofenceInstance *)instance;

#pragma mark Data Helpers

/**
 *  Get Geofence Instances by Point
 *
 *  @param point JMapPoint object to search for geofence instances
 *  @return An array of geofence instances which contains the point
 */
- (nonnull NSArray <JMapGeofenceInstance *>*)getGeofenceInstancesByPoint:(nonnull JMapPoint *)point;

/**
 *  Get Geofence Instances by Waypoint
 *
 *  @param waypoint JMapWaypoint object to search for geofence instances
 *  @return An array of geofence instances which contains the waypoint
 */
- (nonnull NSArray <JMapGeofenceInstance*>*)getGeofenceInstancesByWaypoint:(nonnull JMapWaypoint *)waypoint;

/**
 *  Get Waypoints by Geofence Instance
 *
 *  @param instance JMapGeofenceInstance object to search for waypoints
 *  @return An array of waypoints within the geofence instance
 */
- (nonnull NSArray <JMapWaypoint *>*)getWaypointsInGeofenceInstance:(nonnull JMapGeofenceInstance *)instance;

/**
 *  Get Waypoints by Geofence on the Map
 *
 *  @param geofence JMapGeofenceObject to search for waypoints
 *  @param map Optional param to search for waypoints, if nil then all waypoints are returned for all instances of the geofence
 *  @return An array of waypoints within the geofence
 */
- (nonnull NSArray <JMapWaypoint *>*)getWaypointsInGeofence:(nonnull JMapGeofenceObject *)geofence onMap:(nullable JMapMap *)map;

/**
 *  Get Destinations by Geofence Instance
 *
 *  @param instance JMapGeofenceInstance object to search for destinations
 *  @return An array of destinations within the geofence instance
 */
- (nonnull NSArray <JMapDestination *>*)getDestinationsInGeofenceInstance:(nonnull JMapGeofenceInstance *)instance;

/**
 *  Get Destinations by Geofence on the Map
 *
 *  @param geofence JMapGeofenceObject to search for destinations
 *  @param map Optional param to search for destinations, if nil then all destinations are returned for all instances of the geofence
 *  @return An array of destinations within the geofence
 */
- (nonnull NSArray <JMapDestination *>*)getDestinationsInGeofence:(nonnull JMapGeofenceObject *)geofence onMap:(nullable JMapMap *)map;

/**
 *  Get Amenities by Geofence Instance
 *
 *  @param instance JMapGeofenceInstance object to search for amenities
 *  @return An array of amenities within the geofence instance
 */
- (nonnull NSArray <JMapAmenity *>*)getAmenitiesInGeofenceInstance:(nonnull JMapGeofenceInstance *)instance;

/**
 *  Get Amenities by Geofence on the Map
 *
 *  @param geofence JMapGeofenceObject to search for amenities
 *  @param map Optional param to search for amenities, if nil then all amenities are returned for all instances of the geofence
 *  @return An array of amenities within the geofence
 */
- (nonnull NSArray <JMapAmenity *>*)getAmenitiesInGeofence:(nonnull JMapGeofenceObject *)geofence onMap:(nullable JMapMap *)map;

/**
 *  Get PathTypes by Geofence Instance
 *
 *  @param instance JMapGeofenceInstance object to search for pathTypes
 *  @return An array of pathTypes within the geofence instance
 */
- (nonnull NSArray <JMapPathType *>*)getPathTypesInGeofenceInstance:(nonnull JMapGeofenceInstance *)instance;

/**
 *  Get PathTypes by Geofence on the Map
 *
 *  @param geofence JMapGeofenceObject to search for pathTypes
 *  @param map Optional param to search for pathTypes, if nil then all pathTypes are returned for all instances of the geofence
 *  @return An array of pathTypes within the geofence
 */
- (nonnull NSArray <JMapPathType *>*)getPathTypesInGeofence:(nonnull JMapGeofenceObject *)geofence onMap:(nullable JMapMap *)map;

/**
 *  Get MovingObjects by Geofence Instance
 *
 *  @param instance JMapGeofenceInstance object to search for movingObjects
 *  @return An array of movingObjects within the geofence instance
 */
- (nonnull NSArray <JMapMovingObject *>*)getMovingObjectsInGeofenceInstance:(nonnull JMapGeofenceInstance *)instance;

/**
 *  Get MovingObjects by Geofence on the Map
 *
 *  @param geofence JMapGeofenceObject to search for movingObjects
 *  @param map Optional param to search for movingObjects, if nil then all movingObjects are returned for all instances of the geofence
 *  @return An array of movingObjects within the geofence
 */
- (nonnull NSArray <JMapMovingObject *>*)getMovingObjectsInGeofence:(nonnull JMapGeofenceObject *)geofence onMap:(nullable JMapMap *)map;

/**
 *  Get Closest Waypoint in Geofence Instance to Point
 *
 *  @param instance JMapGeofenceInstance to head to
 *  @param point The reference origin point
 *  @return A JMapWaypoint within the instance closest to origin point
 */
- (nullable JMapWaypoint *)getClosestWaypointInGeofenceInstance:(nonnull JMapGeofenceInstance *)instance toPoint:(nonnull JMapPoint *)point;

/**
 *  Get Closest Waypoint in Geofence to Point on Map
 *
 *  @param geofence JMapGeofenceObject to head to
 *  @param point The reference origin point
 *  @param map Optional map object, if nil then it will search through all geofence instances
 *  @return A JMapWaypoint within the geofence closest to origin point
 */
- (nullable JMapWaypoint *)getClosestWaypointInGeofence:(nonnull JMapGeofenceObject *)geofence toPoint:(nonnull JMapPoint *)point onMap:(nullable JMapMap *)map;

/**
 *  Get Geofence Instance by Id on Map
 *
 *  @param instanceId The geofence instance Id
 *  @param mapId The map Id to search for the instance
 *  @return A JMapGeofenceInstance with the matching Id on the map
 */
- (nullable JMapGeofenceInstance *)getGeofenceInstanceById:(long)instanceId withMapId:(long)mapId;

#pragma mark Delegate Subscription
/**
 *  Listener For Moving Object Animation Completion
 *
 *  @param notification NSNotification callback object
 */
- (void)receiveAnimationComplete:(nonnull NSNotification *)notification;

/**
 *  Method To Subscribe To Listening For Moving Object Animations
 *
 *  @param delegate JMapGeofenceDelegate passed in for triggering delegate callbacks
 */
- (void)watchMovingObjects:(nonnull id <JMapGeofenceDelegate>)delegate;

/**
 *  Method To Unsubscribe To Listening For Moving Object Animations
 */
- (void)unwatchMovingObjects;

@end
