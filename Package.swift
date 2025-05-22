// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
  name: "EvernoteSDK",
  defaultLocalization: "en",
  platforms: [.iOS(.v13)],
  products: [
    .library(
      name: "EvernoteSDK",
      targets: ["EvernoteSDK"]
    )
  ],
  targets: [
    .target(
      name: "EvernoteSDKObjC",
      path: "evernote-sdk-ios",
      resources: [.copy("Resources/ENSDKResources.bundle")],
      publicHeadersPath: "ENSDK/include",
      cSettings: [
        .headerSearchPath("ENSDK/include")
      ]
    ),
    .target(
      name: "EvernoteSDK",
      dependencies: ["EvernoteSDKObjC"],
      path: "SPM",
    ),
  ]
)
