Pod::Spec.new do |s|

  s.name                = 'GfycatKit'
  s.version             = '0.0.45'
  s.summary             = 'GfycatKit for iOS'
  s.description         = 'GfycatKit provides UI components to build experiences using Gfycat.'
  s.homepage            = 'https://developers.gfycat.com/api/'
  s.license             = { :type => 'Commercial', :file => 'LICENSE' }
  s.author              = { 'Gfycat' => 'support@gfycat.com' }
  s.source              = { :git => 'https://github.com/gfycat/GfycatKit.git', :tag => s.version.to_s }
  s.social_media_url    = 'https://twitter.com/gfycat'

  s.platform = :ios, '8.0'
  s.requires_arc = true
  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  s.default_subspec = 'Core'

  s.subspec 'Core' do |sp|
    sp.platform = :ios, '8.0'
    sp.dependency 'GfycatKit/Browser'
    sp.vendored_frameworks = 'Libraries/GfycatKit.framework'
  end

  s.subspec 'Browser' do |sp|
    sp.platform = :ios, '8.0'
    sp.dependency 'YYWebImage'
    sp.dependency 'YYImage/WebP'
    sp.dependency 'GfycatApiKit', '~> 0.0.16'
    sp.resources = 'Libraries/GfycatBrowserKitResources.bundle'
    sp.vendored_frameworks = 'Libraries/GfycatBrowserKit.framework'
    sp.frameworks = 'UIKit', 'AVFoundation', 'CoreMedia', 'Photos', 'SceneKit', 'GLKit', 'CoreMotion', 'ModelIO'
  end

  s.subspec 'PhotoMoments' do |sp|
    sp.platform = :ios, '9.0'
    sp.dependency 'GfycatKit/Core'
    sp.dependency 'FMDB', '~> 2.6'
    sp.dependency 'YYWebImage'
    sp.dependency 'YYImage/WebP'
    sp.resources = 'Libraries/GfycatPhotoMomentsKitResources.bundle'
    sp.vendored_frameworks = 'Libraries/GfycatPhotoMomentsKit.framework'
    sp.weak_frameworks = 'Vision', 'CoreML'
  end

  s.subspec 'Ads' do |sp|
    sp.platform = :ios, '8.0'
    sp.dependency 'GfycatKit/Core'
    sp.dependency 'FBAudienceNetwork', '~> 4.26'
    sp.resources = 'Libraries/GfycatAdsKitResources.bundle'
    sp.vendored_frameworks = 'Libraries/GfycatAdsKit.framework'
  end

end
