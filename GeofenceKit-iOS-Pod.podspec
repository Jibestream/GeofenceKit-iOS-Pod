Pod::Spec.new do |s|
    s.name             = 'GeofenceKit-iOS-Pod'
s.version='1.0.1'
    s.summary          = 'The GeofenceKit-iOS-Pod for the Jibestream iOS SDK.'
    
    s.description      = 'This CocoaPod provides the release version of the GeofenceKit for the Jibestream iOS SDK.'
    
    s.homepage         = 'http://www.jibestream.com/'
    s.author           = { 'louie' => 'lyuen@jibestream.com' }
    s.source           = { :git => 'https://github.com/louieyune/GeofenceKit-iOS-Pod.git', :tag => "#{s.version}" }
    
    s.ios.deployment_target = '9.0'
    
    s.platform = :ios, '9.0'
    s.vendored_frameworks = 'GeofenceKit-iOS-Pod/Frameworks/*.framework'
    
end
