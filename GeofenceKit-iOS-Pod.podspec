Pod::Spec.new do |s|
    s.name             = 'GeofenceKit-iOS-Pod'
s.version='1.1.0'
    s.summary          = 'The GeofenceKit-iOS-Pod for the Jibestream iOS SDK.'
    
    s.description      = 'This CocoaPod provides the release version of the GeofenceKit for the Jibestream iOS SDK.'
    
    s.homepage         = 'http://www.jibestream.com/'
    s.author           = { 'louie' => 'lyuen@jibestream.com' }
    s.source           = { :git => 'https://github.com/Jibestream/GeofenceKit-iOS-Pod', :tag => "#{s.version}" }
    
    s.ios.deployment_target = '10.0'
    
    s.platform = :ios, '10.0'
    s.vendored_frameworks = 'GeofenceKit-iOS-Pod/Frameworks/*.xcframework'
    
end
