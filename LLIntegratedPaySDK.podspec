
Pod::Spec.new do |s|


  s.name         = "LLIntegratedPaySDK"
  s.version      = "0.0.1"
  s.summary      = "上帝也不知道这是啥"

   s.description  = <<-DESC
随便写写咯
                   DESC

  s.homepage     = "https://github.com/SZLCode"

  s.license          = { :file => '../LICENSE' }
  s.author             = { "石智力" => "1527968467@qq.com" }

  s.source = { :git => "https://github.com/SZLCode/ZC_LLIntegratedPaySDK.git", :tag => "#{s.version}" }

  s.source_files = '*'
  s.public_header_files = '*.h'
  
  s.resources = "*.{bundle}"
  s.preserve_paths = '*.a'
  s.vendored_libraries = "*.a"
  s.static_framework = true
  s.dependency "AlipaySDK-iOS"

  s.frameworks = ["SystemConfiguration", "CoreTelephony"]
  s.libraries = ["z", "sqlite3.0", "c++"]
  s.ios.deployment_target = '8.0'

end
