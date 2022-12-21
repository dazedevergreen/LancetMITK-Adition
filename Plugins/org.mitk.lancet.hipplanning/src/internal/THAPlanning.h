/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/


#ifndef THAPlanning_h
#define THAPlanning_h

#include <berryISelectionListener.h>

#include <QmitkAbstractView.h>

#include "ui_THAPlanningControls.h"

#include "mitkPointSet.h"

/**
  \brief THAPlanning

  \warning  This class is not yet documented. Use "git blame" and ask the author to provide basic documentation.

  \sa QmitkAbstractView
  \ingroup ${plugin_target}_internal
*/
class THAPlanning : public QmitkAbstractView
{
  // this is needed for all Qt objects that should have a Qt meta-object
  // (everything that derives from QObject and wants to have signal/slots)
  Q_OBJECT

public:
  static const std::string VIEW_ID;

protected:
  virtual void CreateQtPartControl(QWidget *parent) override;

  virtual void SetFocus() override;

  /// \brief called by QmitkFunctionality when DataManager's selection has changed
  virtual void OnSelectionChanged(berry::IWorkbenchPart::Pointer source,
                                  const QList<mitk::DataNode::Pointer> &nodes) override;

  /// \brief Called when the user clicks the GUI button

  Ui::THAPlanningControls m_Controls;

	// Test the old THA_Model
  double m_hipLength_initMinusContra{ 0 };
  double m_hipOffset_initMinusContra{ 0 };

  double m_hipLength_currentMinusContra{ 0 };
  double m_hipOffset_currentMinusContra{ 0 };

  double m_hipLength_currentMinusInit{ 0 }; // hipLength_currentMinusContra - hipLength_initMinusContra
  double m_hipOffset_currentMinusInit{ 0 }; // hipOffset_currentMinusContra - hipOffset_initMinusContra

  void InitialConstruct();
  void CurrentConstruct();

  void ConstructTHAmodel(); // update m_hipLength_currentMinusContra & m_hipOffset_currentMinusContra


	//----------- New THA model with specification on --------------
	// https://gn1phhht53.feishu.cn/wiki/wikcnmt3TwoT0lS5r3NHFNH5U4f?table=tblk7ke86l8RyAoN&view=vew1Kd7wVv

	//------- Physiological landmarks --------
    //------ Left femur --------
  mitk::PointSet::Pointer m_pset_lesserTrochanter_L;
  mitk::PointSet::Pointer m_pset_femurCOR_L;
  mitk::PointSet::Pointer m_pset_femurCanal_L; // left femur anatomical axis
  mitk::PointSet::Pointer m_pset_epicondyles_L;
  mitk::PointSet::Pointer m_pset_neckCenter_L;

	//------- Right femur --------
  mitk::PointSet::Pointer m_pset_lesserTrochanter_R;
  mitk::PointSet::Pointer m_pset_femurCOR_R;
  mitk::PointSet::Pointer m_pset_femurCanal_R; // right femur anatomical axis 
  mitk::PointSet::Pointer m_pset_epicondyles_R;
  mitk::PointSet::Pointer m_pset_neckCenter_R;

	//------- Pelvis -----------
  mitk::PointSet::Pointer m_pset_ASIS;
  mitk::PointSet::Pointer m_pset_midline;

	// ------- Physiological value calculation --------
 
    // Operation side
  int m_operationSide{ 0 }; // right femur: 0   left femur: 1

	//coarse Data collection
  void CollectTHAdata();

    // Femoral version
  double CalculateNativeFemoralVersions();
  void On_pushButton_femoralVersion_clicked();

	// Append the geometry matrix to the point
  mitk::Point3D GetPointWithGeometryMatrix(const mitk::PointSet::Pointer inputPointSet, const unsigned pointIndex);

  // Append the geometry matrix to the pointSet
  mitk::PointSet::Pointer GetPointSetWithGeometryMatrix(const mitk::PointSet::Pointer inputPointSet);

  

};

#endif // THAPlanning_h
