Pod::Spec.new do |s|

  s.name                = 'GfycatKeyboardKit'
  s.version             = '0.0.6'
  s.summary             = 'GfycatKeyboardKit for iOS'
  s.description         = 'GfycatKeyboardKit provides interface components to build Gfycat Keyboard.'
  s.homepage            = 'https://developers.gfycat.com/api/'
  s.license             = { :type => 'Commercial', :file => 'LICENSE' }
  s.author              = { 'Gfycat' => 'support@gfycat.com' }
  s.source              = { :git => 'https://github.com/victor-pavlychko/GfycatKeyboardKit.git', :tag => s.version.to_s }
  s.social_media_url    = 'https://twitter.com/gfycat'

  s.platform            = :ios, '8.0'
  s.requires_arc        = true
  s.public_header_files = 'Headers/*.h'
  s.source_files        = ['Headers/*.h', 'Sources/*']
  s.vendored_libraries  = 'Libraries/libGfycatKeyboard.a'
  s.resource            = 'Resources/*.bundle'

  s.dependency 'YYWebImage'
  s.dependency 'YYImage/WebP'
  s.dependency 'GfycatApiKit'

end
