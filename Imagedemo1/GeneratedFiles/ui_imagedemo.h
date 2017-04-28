/********************************************************************************
** Form generated from reading UI file 'imagedemo.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDEMO_H
#define UI_IMAGEDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImagedemoClass
{
public:
    QAction *actionQwdq;
    QAction *actionOpen_Image;
    QAction *actionRestore_Image;
    QAction *action_Exit;
    QAction *actionColor_gray_scale;
    QAction *actionImage_inversion;
    QAction *actionVertical_mirror;
    QAction *actionHorizontal_mirror;
    QAction *action_180_degree_rotation;
    QAction *action30_degree_rotation;
    QAction *actionAffine_transformation;
    QAction *actionPerspective_transformation;
    QAction *actionBrightness_transformation;
    QAction *actionGrayscale_image_histogram;
    QAction *actionHistogram_equalization;
    QAction *actionNeighborhood_average;
    QAction *actionGauss_Filter;
    QAction *actionMedian_filter;
    QAction *actionSobel_Boundary_detection;
    QAction *actionLaplace_Boundary_detection;
    QAction *actionSelect_the_threshold;
    QAction *actionAdaptive_threshold;
    QAction *actionBased_on_global_threshold;
    QAction *actionCorrosion;
    QAction *actionExpand;
    QAction *actionOpen_operation;
    QAction *actionClosed_operation;
    QAction *actionMorphological_gradient;
    QAction *actionTop_hat_transformation;
    QAction *actionTop_hat_transformation_2;
    QWidget *centralWidget;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menuLiyu;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QMenu *menu_7;
    QMenu *menu_8;
    QMenu *menu_9;
    QMenu *menu_10;
    QMenu *menu_11;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImagedemoClass)
    {
        if (ImagedemoClass->objectName().isEmpty())
            ImagedemoClass->setObjectName(QStringLiteral("ImagedemoClass"));
        ImagedemoClass->resize(945, 579);
        actionQwdq = new QAction(ImagedemoClass);
        actionQwdq->setObjectName(QStringLiteral("actionQwdq"));
        actionOpen_Image = new QAction(ImagedemoClass);
        actionOpen_Image->setObjectName(QStringLiteral("actionOpen_Image"));
        actionOpen_Image->setCheckable(false);
        actionRestore_Image = new QAction(ImagedemoClass);
        actionRestore_Image->setObjectName(QStringLiteral("actionRestore_Image"));
        action_Exit = new QAction(ImagedemoClass);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        actionColor_gray_scale = new QAction(ImagedemoClass);
        actionColor_gray_scale->setObjectName(QStringLiteral("actionColor_gray_scale"));
        actionImage_inversion = new QAction(ImagedemoClass);
        actionImage_inversion->setObjectName(QStringLiteral("actionImage_inversion"));
        actionVertical_mirror = new QAction(ImagedemoClass);
        actionVertical_mirror->setObjectName(QStringLiteral("actionVertical_mirror"));
        actionHorizontal_mirror = new QAction(ImagedemoClass);
        actionHorizontal_mirror->setObjectName(QStringLiteral("actionHorizontal_mirror"));
        action_180_degree_rotation = new QAction(ImagedemoClass);
        action_180_degree_rotation->setObjectName(QStringLiteral("action_180_degree_rotation"));
        action30_degree_rotation = new QAction(ImagedemoClass);
        action30_degree_rotation->setObjectName(QStringLiteral("action30_degree_rotation"));
        actionAffine_transformation = new QAction(ImagedemoClass);
        actionAffine_transformation->setObjectName(QStringLiteral("actionAffine_transformation"));
        actionPerspective_transformation = new QAction(ImagedemoClass);
        actionPerspective_transformation->setObjectName(QStringLiteral("actionPerspective_transformation"));
        actionBrightness_transformation = new QAction(ImagedemoClass);
        actionBrightness_transformation->setObjectName(QStringLiteral("actionBrightness_transformation"));
        actionGrayscale_image_histogram = new QAction(ImagedemoClass);
        actionGrayscale_image_histogram->setObjectName(QStringLiteral("actionGrayscale_image_histogram"));
        actionHistogram_equalization = new QAction(ImagedemoClass);
        actionHistogram_equalization->setObjectName(QStringLiteral("actionHistogram_equalization"));
        actionNeighborhood_average = new QAction(ImagedemoClass);
        actionNeighborhood_average->setObjectName(QStringLiteral("actionNeighborhood_average"));
        actionGauss_Filter = new QAction(ImagedemoClass);
        actionGauss_Filter->setObjectName(QStringLiteral("actionGauss_Filter"));
        actionMedian_filter = new QAction(ImagedemoClass);
        actionMedian_filter->setObjectName(QStringLiteral("actionMedian_filter"));
        actionSobel_Boundary_detection = new QAction(ImagedemoClass);
        actionSobel_Boundary_detection->setObjectName(QStringLiteral("actionSobel_Boundary_detection"));
        actionLaplace_Boundary_detection = new QAction(ImagedemoClass);
        actionLaplace_Boundary_detection->setObjectName(QStringLiteral("actionLaplace_Boundary_detection"));
        actionSelect_the_threshold = new QAction(ImagedemoClass);
        actionSelect_the_threshold->setObjectName(QStringLiteral("actionSelect_the_threshold"));
        actionAdaptive_threshold = new QAction(ImagedemoClass);
        actionAdaptive_threshold->setObjectName(QStringLiteral("actionAdaptive_threshold"));
        actionBased_on_global_threshold = new QAction(ImagedemoClass);
        actionBased_on_global_threshold->setObjectName(QStringLiteral("actionBased_on_global_threshold"));
        actionCorrosion = new QAction(ImagedemoClass);
        actionCorrosion->setObjectName(QStringLiteral("actionCorrosion"));
        actionExpand = new QAction(ImagedemoClass);
        actionExpand->setObjectName(QStringLiteral("actionExpand"));
        actionOpen_operation = new QAction(ImagedemoClass);
        actionOpen_operation->setObjectName(QStringLiteral("actionOpen_operation"));
        actionClosed_operation = new QAction(ImagedemoClass);
        actionClosed_operation->setObjectName(QStringLiteral("actionClosed_operation"));
        actionMorphological_gradient = new QAction(ImagedemoClass);
        actionMorphological_gradient->setObjectName(QStringLiteral("actionMorphological_gradient"));
        actionTop_hat_transformation = new QAction(ImagedemoClass);
        actionTop_hat_transformation->setObjectName(QStringLiteral("actionTop_hat_transformation"));
        actionTop_hat_transformation_2 = new QAction(ImagedemoClass);
        actionTop_hat_transformation_2->setObjectName(QStringLiteral("actionTop_hat_transformation_2"));
        centralWidget = new QWidget(ImagedemoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 10, 601, 521));
        ImagedemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImagedemoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 945, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menuLiyu = new QMenu(menuBar);
        menuLiyu->setObjectName(QStringLiteral("menuLiyu"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_6 = new QMenu(menuBar);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        menu_7 = new QMenu(menuBar);
        menu_7->setObjectName(QStringLiteral("menu_7"));
        menu_8 = new QMenu(menuBar);
        menu_8->setObjectName(QStringLiteral("menu_8"));
        menu_9 = new QMenu(menuBar);
        menu_9->setObjectName(QStringLiteral("menu_9"));
        menu_10 = new QMenu(menuBar);
        menu_10->setObjectName(QStringLiteral("menu_10"));
        menu_11 = new QMenu(menuBar);
        menu_11->setObjectName(QStringLiteral("menu_11"));
        ImagedemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImagedemoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImagedemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImagedemoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImagedemoClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menuLiyu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menuBar->addAction(menu_6->menuAction());
        menuBar->addAction(menu_7->menuAction());
        menuBar->addAction(menu_8->menuAction());
        menuBar->addAction(menu_9->menuAction());
        menuBar->addAction(menu_10->menuAction());
        menuBar->addAction(menu_11->menuAction());
        menu->addAction(actionOpen_Image);
        menu->addAction(actionRestore_Image);
        menu->addAction(action_Exit);
        menu_2->addAction(actionColor_gray_scale);
        menu_2->addAction(actionImage_inversion);
        menu_2->addSeparator();
        menu_2->addAction(actionVertical_mirror);
        menu_2->addAction(actionHorizontal_mirror);
        menu_2->addAction(action_180_degree_rotation);
        menu_2->addAction(action30_degree_rotation);
        menu_2->addSeparator();
        menu_2->addAction(actionAffine_transformation);
        menu_2->addAction(actionPerspective_transformation);
        menu_2->addSeparator();
        menu_2->addAction(actionBrightness_transformation);
        menu_2->addAction(actionGrayscale_image_histogram);
        menu_2->addAction(actionHistogram_equalization);
        menuLiyu->addAction(actionNeighborhood_average);
        menuLiyu->addAction(actionGauss_Filter);
        menuLiyu->addAction(actionMedian_filter);
        menuLiyu->addSeparator();
        menuLiyu->addAction(actionSobel_Boundary_detection);
        menuLiyu->addAction(actionLaplace_Boundary_detection);
        menu_3->addAction(actionSelect_the_threshold);
        menu_3->addAction(actionAdaptive_threshold);
        menu_3->addAction(actionBased_on_global_threshold);
        menu_5->addAction(actionCorrosion);
        menu_5->addAction(actionExpand);
        menu_5->addAction(actionOpen_operation);
        menu_5->addAction(actionClosed_operation);
        menu_5->addAction(actionMorphological_gradient);
        menu_5->addSeparator();
        menu_5->addAction(actionTop_hat_transformation);
        menu_5->addAction(actionTop_hat_transformation_2);

        retranslateUi(ImagedemoClass);

        QMetaObject::connectSlotsByName(ImagedemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImagedemoClass)
    {
        ImagedemoClass->setWindowTitle(QApplication::translate("ImagedemoClass", "Imagedemo", 0));
        actionQwdq->setText(QApplication::translate("ImagedemoClass", "qwdq", 0));
        actionOpen_Image->setText(QApplication::translate("ImagedemoClass", "Open Image", 0));
        actionRestore_Image->setText(QApplication::translate("ImagedemoClass", "Restore Image", 0));
        action_Exit->setText(QApplication::translate("ImagedemoClass", "   Exit", 0));
        actionColor_gray_scale->setText(QApplication::translate("ImagedemoClass", "Color gray scale", 0));
        actionImage_inversion->setText(QApplication::translate("ImagedemoClass", "Image inversion\n"
"", 0));
        actionVertical_mirror->setText(QApplication::translate("ImagedemoClass", "Vertical mirror", 0));
        actionHorizontal_mirror->setText(QApplication::translate("ImagedemoClass", "Horizontal mirror", 0));
        action_180_degree_rotation->setText(QApplication::translate("ImagedemoClass", "180 degree rotation", 0));
        action30_degree_rotation->setText(QApplication::translate("ImagedemoClass", "30 degree rotation", 0));
        actionAffine_transformation->setText(QApplication::translate("ImagedemoClass", "Affine transformation", 0));
        actionPerspective_transformation->setText(QApplication::translate("ImagedemoClass", "Perspective transformation", 0));
        actionBrightness_transformation->setText(QApplication::translate("ImagedemoClass", "Brightness transformation", 0));
        actionGrayscale_image_histogram->setText(QApplication::translate("ImagedemoClass", "Grayscale image histogram", 0));
        actionHistogram_equalization->setText(QApplication::translate("ImagedemoClass", "Histogram equalization", 0));
        actionNeighborhood_average->setText(QApplication::translate("ImagedemoClass", "Neighborhood average", 0));
        actionGauss_Filter->setText(QApplication::translate("ImagedemoClass", "Gauss Filter", 0));
        actionMedian_filter->setText(QApplication::translate("ImagedemoClass", "Median filter", 0));
        actionSobel_Boundary_detection->setText(QApplication::translate("ImagedemoClass", "Sobel  Boundary detection", 0));
        actionLaplace_Boundary_detection->setText(QApplication::translate("ImagedemoClass", "Laplace Boundary detection", 0));
        actionSelect_the_threshold->setText(QApplication::translate("ImagedemoClass", "Select the threshold", 0));
        actionAdaptive_threshold->setText(QApplication::translate("ImagedemoClass", "Adaptive threshold", 0));
        actionBased_on_global_threshold->setText(QApplication::translate("ImagedemoClass", "Otsu", 0));
        actionCorrosion->setText(QApplication::translate("ImagedemoClass", "corrosion", 0));
        actionExpand->setText(QApplication::translate("ImagedemoClass", "expand", 0));
        actionOpen_operation->setText(QApplication::translate("ImagedemoClass", "Open operation", 0));
        actionClosed_operation->setText(QApplication::translate("ImagedemoClass", "Closed operation", 0));
        actionMorphological_gradient->setText(QApplication::translate("ImagedemoClass", "Morphological gradient", 0));
        actionTop_hat_transformation->setText(QApplication::translate("ImagedemoClass", "Top hat transformation", 0));
        actionTop_hat_transformation_2->setText(QApplication::translate("ImagedemoClass", "Trough detection", 0));
        label->setText(QString());
        menu->setTitle(QApplication::translate("ImagedemoClass", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("ImagedemoClass", "\347\202\271\345\244\204\347\220\206", 0));
        menuLiyu->setTitle(QApplication::translate("ImagedemoClass", "\351\202\273\345\237\237\345\244\204\347\220\206", 0));
        menu_3->setTitle(QApplication::translate("ImagedemoClass", "\344\272\214\345\200\274\345\214\226", 0));
        menu_4->setTitle(QApplication::translate("ImagedemoClass", "\344\272\214\345\200\274\345\214\226\345\244\204\347\220\206", 0));
        menu_5->setTitle(QApplication::translate("ImagedemoClass", "\345\275\242\346\200\201\345\255\246\345\244\204\347\220\206", 0));
        menu_6->setTitle(QApplication::translate("ImagedemoClass", "\345\275\251\350\211\262\345\233\276\345\203\217\345\244\204\347\220\206", 0));
        menu_7->setTitle(QApplication::translate("ImagedemoClass", "\347\273\274\345\220\210\345\244\204\347\220\206", 0));
        menu_8->setTitle(QApplication::translate("ImagedemoClass", "\345\212\250\346\200\201\346\243\200\346\265\213", 0));
        menu_9->setTitle(QApplication::translate("ImagedemoClass", "\350\247\206\351\242\221\351\207\207\351\233\206\346\222\255\346\224\276", 0));
        menu_10->setTitle(QApplication::translate("ImagedemoClass", "\345\233\276\345\203\217\351\207\207\351\233\206\345\217\212\345\205\266\345\256\203", 0));
        menu_11->setTitle(QApplication::translate("ImagedemoClass", "\345\205\263\344\272\216", 0));
    } // retranslateUi

};

namespace Ui {
    class ImagedemoClass: public Ui_ImagedemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDEMO_H
