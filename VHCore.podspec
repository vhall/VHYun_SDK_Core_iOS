Pod::Spec.new do |s|
  s.name          = "VHCore"
  s.version       = "2.3.2"
  s.summary       = "VHall iOS SDK #{s.name.to_s}"
  s.homepage      = 'https://www.vhall.com'
  s.author        = { "LiGuoliang" => "guoliang.li@vhall.com" }
  s.license       = { :type => "MIT", :file => "LICENSE" }
  s.source          = { :git => "https://github.com/vhall/VHYun_SDK_Core_iOS.git", :tag => s.version.to_s}
  s.platform        = :ios, '8.0'
  s.module_name     = "#{s.name.to_s}"
  s.vendored_frameworks = 'VHYunFrameworks/*.framework'
  s.pod_target_xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/**',
    'HEADER_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/**'
  }
end