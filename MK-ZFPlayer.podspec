#
#  Be sure to run `pod spec lint MK-ZFPlayer.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "MK-ZFPlayer"
  s.version      = "1.0.0"
  s.summary      = "Fork from ZFPlayer"
  s.description  = <<-DESC
                    Fork from ZFPlayer.
                   DESC
  s.homepage     = "https://github.com/Mosoink/MK-ZFPlayer"
  s.license      = "https://github.com/Mosoink/MK-ZFPlayer"
  s.author       = { "Mosoink" => "zhibin.cai@mosoink.com" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/Mosoink/MK-ZFPlayer.git" }

  # s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }

  s.resources    = "ZFPlayer/*.bundle"
  
  s.source_files = [
    'ZFPlayer/*.{h,m}'
  ]
  s.public_header_files = [
    'ZFPlayer/*.h'
  ]
  s.frameworks = [
      'AVFoundation',
      'MediaPlayer'
  ]
  s.ios.dependency 'Masonry', '~> 1.0.2'
end
