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
        // categories browsing settings
        gfycatBrowserSettings.categoryPickerSettings.scrollDirection = .vertical
        gfycatBrowserSettings.categoryPickerSettings.cornerRadius = 0
        gfycatBrowserSettings.categoryPickerSettings.itemSpacing = 2
        gfycatBrowserSettings.categoryPickerSettings.contentInset = UIEdgeInsetsMake(4, 8, 16, 8)
        gfycatBrowserSettings.categoryPickerSettings.categoryGridSize = 4
        gfycatBrowserSettings.categoryPickerSettings.categoryAspectRatio = CGSize(width: 1, height: 1)
        gfycatBrowserSettings.categoryPickerSettings.categoryMediaFormat = .webp
        gfycatBrowserSettings.categoryPickerSettings.enableRecentItems = true
        gfycatBrowserSettings.categoryPickerSettings.enablePhotoMoments = true
        // --register cells for custom models
        gfycatBrowserSettings.categoryPickerSettings.registerCellView(ColorCollectionViewCell.self, forCategoryModel: ColorModel.self)
        // media list browsing settings
        gfycatBrowserSettings.mediaPickerSettings.scrollDirection = .vertical
        gfycatBrowserSettings.mediaPickerSettings.videoMediaFormat = .largeWebp
        gfycatBrowserSettings.mediaPickerSettings.cornerRadius = 0
        gfycatBrowserSettings.mediaPickerSettings.itemSpacing = 2
        gfycatBrowserSettings.mediaPickerSettings.contentInset = UIEdgeInsetsMake(4, 8, 16, 8)
        // recents list browsing settings
        gfycatBrowserSettings.recentsMediaPickerSettings.scrollDirection = .vertical
        gfycatBrowserSettings.recentsMediaPickerSettings.videoMediaFormat = .webp
        gfycatBrowserSettings.recentsMediaPickerSettings.cornerRadius = 40
        gfycatBrowserSettings.recentsMediaPickerSettings.itemSpacing = 2
        gfycatBrowserSettings.recentsMediaPickerSettings.videoGridSize = 3
        gfycatBrowserSettings.recentsMediaPickerSettings.contentInset = UIEdgeInsetsMake(4, 8, 16, 8)
        // grouping of recent items
        gfycatBrowserSettings.recentsMediaPickerSettings.enableRecentsGrouping = true
        // uncomment to enable photo moments
//        gfycatBrowserSettings.recentsMediaPickerSettings.enableSharedGrouping = true
        gfycatBrowserSettings.recentsMediaPickerSettings.enableFavoriteItems = true

        let browser = GFYBrowserViewController(settings: gfycatBrowserSettings)
        browser.delegate = self
        activeViewController = browser
    }
}

extension SecondViewController: GFYBrowserDelegate {
    // MARK: - GFYCategoryPickerDelegate
    func gfycatCategoryPicker(_ picker: GFYCategoryPickerViewController, customizeModel model: [GFYCollectionViewSection]) -> [GFYCollectionViewSection] {
        // add model to the .content section
        let specialContentCellModels: [GFYArrangable] = [ColorModel(withColor: .yellow)]
        var model = model
        if let sectionIndex = model.index(where: { $0.identifier == .content }) {
            model[sectionIndex] = GFYCollectionViewSectionArray(identifier: .content,
                                                                items: specialContentCellModels.compactMap({ $0 }) + model[sectionIndex].items)
        } else {
            model.append(GFYCollectionViewSectionArray(identifier: .content,
                                                       items: specialContentCellModels.compactMap({ $0 })))
        }

        // add more sections before .content section
        guard let contentSectionIndex = model.index(where: { $0.identifier == .content }) else {
            return model
        }
        
        let greenSectionIdentifier = GFYCollectionViewSectionIdentifier(rawValue: "greenContent")
        let greenSectionModels: [GFYArrangable] = [ColorModel(withColor: .green), ColorModel(withColor: .green)]
        model.insert(GFYCollectionViewSectionArray.init(identifier: greenSectionIdentifier, items: greenSectionModels), at: contentSectionIndex)
        
        let redSectionIdentifier = GFYCollectionViewSectionIdentifier(rawValue: "redContent")
        let redSectionModels: [GFYArrangable] = [ColorModel(withColor: .red), ColorModel(withColor: .red), ColorModel(withColor: .red)]
        model.insert(GFYCollectionViewSectionArray.init(identifier: redSectionIdentifier, items: redSectionModels), at: contentSectionIndex)
        
        return model
    }
    
    func gfycatCategoryPicker(_ picker: GFYCategoryPickerViewController, didSelectItem model: Any) {
        print("Did Select custom cell \(model)")
    }

    // MARK: - GFYMediaPickerViewController
    func gfycatMediaPicker(_ picker: GFYMediaPickerViewController, didSelect media: GfycatMedia, with source: GFYArraySource) {
        print("Did Select media: \(media)")
    }
}

