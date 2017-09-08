//
//  SecondViewController.swift
//  GfycatBrowser
//
//  Created by Oleksii Chubenko on 4/13/17.
//  Copyright © 2017 Gfycat. All rights reserved.
//

import UIKit
import GfycatKit

class ColorModel: NSObject, GFYArrangable {

    var color: UIColor?
    init(withColor color: UIColor?) {
        self.color = color
    }
    
    func copy(with zone: NSZone? = nil) -> Any {
        return ColorModel(withColor: color)
    }
    
    override func isEqual(_ object: Any?) -> Bool {
        guard let colorModel = object as? ColorModel else {
            return false
        }
        guard color != nil else {
            return colorModel.color == nil
        }
        return color!.isEqual(_: colorModel.color)
    }
    
    var modelIdentity: NSCopying & NSObjectProtocol { return self }
    var presentationIdentity: NSCopying & NSObjectProtocol { return color ?? .clear }
}

class ColorCollectionViewCell: GFYCollectionViewCell<ColorModel> {
    override func present(_ model: ColorModel, animated: Bool) {
        backgroundColor = model.color
    }
    
    override static func height(forModel model: Any, width itemWidth: CGFloat) -> CGFloat {
        guard (model as? ColorModel) != nil else {
            return super.height(forModel: model, width: itemWidth)
        }
        return 2.5 * itemWidth
    }
}

class SecondViewController: GFYSimpleContainerViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        let gfycatBrowserSettings = GFYBrowserSettings()
        gfycatBrowserSettings.enableSearchHistory = true
        gfycatBrowserSettings.enableRecentItems = true
        gfycatBrowserSettings.enablePhotoMoments = true
        
        gfycatBrowserSettings.scrollDirection = .vertical
        gfycatBrowserSettings.cornerRadius = 0
        gfycatBrowserSettings.itemSpacing = 2
        gfycatBrowserSettings.contentInset = UIEdgeInsetsMake(4, 8, 16, 8)
        gfycatBrowserSettings.categoryGridSize = 4
        gfycatBrowserSettings.categoryAspectRatio = CGSize(width: 1, height: 1)
        gfycatBrowserSettings.categoryMediaFormat = .webP
        gfycatBrowserSettings.videoMediaFormat = .webP

        // register cells for custom models
        gfycatBrowserSettings.registerCellView(ColorCollectionViewCell.self, forCategoryModel: ColorModel.self)
        
        let browser = GFYBrowserViewController(settings: gfycatBrowserSettings)
        browser.delegate = self
        activeViewController = browser
    }
}

extension SecondViewController: GFYBrowserDelegate {
    
    func gfycatCategoryPicker(_ picker: GFYCategoryPickerViewController, customizeModel model: [[Any]]) -> [[Any]] {
        let greenSectionModels: [Any] = [ColorModel(withColor: .green), ColorModel(withColor: .green)]
        let redSectionModel: [Any] = [ColorModel(withColor: .red), ColorModel(withColor: .red), ColorModel(withColor: .red)]
        let addedSections = [greenSectionModels] + [redSectionModel]
        
        if model.count > 0, model[0].count > 0 {
            let specialModels: [Any] = [ColorModel(withColor: .yellow)]
            return addedSections + [specialModels + model[0]]
        } else {
            return addedSections
        }
    }
    
    func gfycatCategoryPicker(_ picker: GFYCategoryPickerViewController, didSelectItem model: Any) {
        NSLog("Did Select custom cell: %@", (model as? NSObject) ?? "NULL")
    }
    
    func gfycatMediaPicker(_ picker: GFYMediaPickerViewController, didSelect media: GfycatMedia, with source: GFYArraySource) {
        NSLog("Did Select media: %@", media)
    }
}

