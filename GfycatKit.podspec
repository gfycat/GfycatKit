Pod::Spec.new do |s|

  s.name                = 'GfycatKit'
  s.version             = '0.0.31'
  s.summary             = 'GfycatKit for iOS'
  s.description         = 'GfycatKit provides UI components to build experiences using Gfycat.'
  s.homepage            = 'https://developers.gfycat.com/api/'
  s.license             = { :type => 'Commercial', :file => 'LICENSE' }
  s.author              = { 'Gfycat' => 'support@gfycat.com' }
  s.source              = { :git => 'https://github.com/gfycat/GfycatKit.git', :tag => s.version.to_s }
  s.social_media_url    = 'https://twitter.com/gfycat'

  s.platform            = :ios, '8.0'
  s.requires_arc        = true
  s.public_header_files = 'Headers/*.h'
  s.source_files        = ['Headers/*.h', 'Sources/*']
  s.vendored_libraries  = 'Libraries/libGfycat.a'
  s.resource            = 'Resources/*.bundle'
  s.xcconfig            = { 'OTHER_LDFLAGS' => '-ObjC' }

  s.dependency 'YYWebImage'
  s.dependency 'YYImage/WebP'
  s.dependency 'GfycatApiKit', '~> 0.0.5'

end
