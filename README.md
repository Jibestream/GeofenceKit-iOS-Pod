# GeofenceKit-iOS-Pod

[![CI Status](https://img.shields.io/travis/louieyuen/GeofenceKit-iOS-Pod.svg?style=flat)](https://travis-ci.org/louieyuen/GeofenceKit-iOS-Pod)
[![Version](https://img.shields.io/cocoapods/v/GeofenceKit-iOS-Pod.svg?style=flat)](https://cocoapods.org/pods/GeofenceKit-iOS-Pod)
[![License](https://img.shields.io/cocoapods/l/GeofenceKit-iOS-Pod.svg?style=flat)](https://cocoapods.org/pods/GeofenceKit-iOS-Pod)
[![Platform](https://img.shields.io/cocoapods/p/GeofenceKit-iOS-Pod.svg?style=flat)](https://cocoapods.org/pods/GeofenceKit-iOS-Pod)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

- **iOS 15.0 or later**, as of 2.0.0. Release 1.1.0 and earlier declare a lower
  floor (the podspec carried conflicting iOS 9.0 and 10.0 declarations) and
  remain resolvable, so a project that cannot move to iOS 15 yet can stay
  pinned to 1.1.0.
- **Xcode 15 or later** for Swift Package Manager (`Package.swift` declares
  `swift-tools-version:5.9`). CocoaPods has no additional Xcode requirement
  beyond what the binary itself needs.
- **[JMapiOSSDK](https://github.com/Jibestream/JMap-iOS-SDK-Pod) 6.0.0 or later.**
  `JMapGeofenceKit`'s public headers `#import <JMapCoreKit/JMapCoreKit.h>` and
  `<JMapControllerKit/JMapControllerKit.h>`, so the SDK is a compile-time
  requirement and not merely a link-time one. Both manifests declare it, so
  either package manager resolves it for you.
- **`-ObjC` in your target's Other Linker Flags.** `JMapGeofenceKit` itself contains no
  Objective-C categories and needs no linker flags of its own, but the
  JMapiOSSDK frameworks underneath it do: without `-ObjC` their categories are
  not registered at runtime, producing an `unrecognized selector` crash during
  map parsing. The build succeeds either way, so the failure is silent until
  run time. CocoaPods writes this flag into its generated xcconfig
  automatically; with Swift Package Manager you must set it yourself.

## Installation

GeofenceKit supports **both** Swift Package Manager and CocoaPods. Both are served
from this one repository and the same git tag: SPM reads `Package.swift`,
CocoaPods reads `GeofenceKit-iOS-Pod.podspec`, and both point at the same
XCFramework under `GeofenceKit-iOS-Pod/Frameworks/`. Each ignores the other's
manifest.

> **Pick one.** Adding GeofenceKit through both CocoaPods and Swift Package Manager in
> the same project links the framework twice and fails with duplicate symbol
> errors. The same applies to `JMapiOSSDK` underneath it: both must come from
> the same package manager.

### Swift Package Manager (2.0.0 and later)

In Xcode, choose **File > Add Package Dependencies...**, enter
`https://github.com/Jibestream/GeofenceKit-iOS-Pod.git`, pick **Up to Next Major Version**
from `2.0.0`, and add the `JMapGeofenceKit` product to your app target.

Or, in a `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/Jibestream/GeofenceKit-iOS-Pod.git", from: "2.0.0")
],
targets: [
    .target(
        name: "YourTarget",
        dependencies: [.product(name: "JMapGeofenceKit", package: "GeofenceKit-iOS-Pod")]
    )
]
```

The product provides the `JMapGeofenceKit` module and brings in JMapiOSSDK
(`JMapCoreKit`, `JMapRenderingKit`, `JMapControllerKit`) transitively, so you do
not add that package separately.

Swift Package Manager support is available from **2.0.0** onward. Earlier tags do
not contain a `Package.swift` and cannot be resolved by SPM.

### CocoaPods (deprecated)

CocoaPods support continues for now but will be removed in a future release;
please move to Swift Package Manager.

To install, simply add the following line to your Podfile:

```ruby
pod 'GeofenceKit-iOS-Pod', :git => 'https://github.com/Jibestream/GeofenceKit-iOS-Pod.git'
```

For installing the first time run:
```ruby
pod install
```

To get the latest version of the pod run:
```ruby
pod update
```

## Author

Louie, lyuen@jibestream.com
